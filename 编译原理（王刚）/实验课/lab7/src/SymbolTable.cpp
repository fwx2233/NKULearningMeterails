#include "SymbolTable.h"
#include <iostream>
#include <sstream>
bool check;

SymbolEntry::SymbolEntry(Type *type, int kind) 
{
    this->type = type;
    this->kind = kind;
}

ConstantSymbolEntry::ConstantSymbolEntry(Type *type, int value) : SymbolEntry(type, SymbolEntry::CONSTANT)
{
    this->value = value;
}

std::string ConstantSymbolEntry::toStr()
{
    std::ostringstream buffer;
    buffer << value;
    return buffer.str();
}

BoolSymbolEntry::BoolSymbolEntry(Type *type, int value) : ConstantSymbolEntry(type,value)
{
}

std::string BoolSymbolEntry::toStr()
{
    std::string s;
    if(value)
    {
        s="true";
    }
    else{
        s="false";
    }
    return s;
}

IdentifierSymbolEntry::IdentifierSymbolEntry(Type *type, std::string name, int scope) : SymbolEntry(type, SymbolEntry::VARIABLE), name(name)
{
    this->scope = scope;
    addr = nullptr;
}

std::string IdentifierSymbolEntry::toStr()
{
    return "@" + name;
}

TemporarySymbolEntry::TemporarySymbolEntry(Type *type, int label) : SymbolEntry(type, SymbolEntry::TEMPORARY)
{
    this->label = label;
}

std::string TemporarySymbolEntry::toStr()
{
    std::ostringstream buffer;
    buffer << "%t" << label;
    return buffer.str();
}

SymbolTable::SymbolTable()
{
    prev = nullptr;
    level = 0;

    Type *funcType;
    std::vector<Type*> *paramsType = new std::vector<Type*>;
    IdentifierSymbolEntry*se;

    Type* tempint = TypeSystem::intType;
    paramsType->push_back(tempint);

    funcType = new FunctionType(TypeSystem::voidType, *paramsType);
    se=new IdentifierSymbolEntry(funcType,"putint",getLevel());
    se->SetSysFunc();
    install("putint", se);

    funcType = new FunctionType(TypeSystem::intType, {});
    se=new IdentifierSymbolEntry(funcType,"getint",getLevel());
    se->SetSysFunc();
    install("getint", se);

    funcType = new FunctionType(TypeSystem::intType, {});
    se = new IdentifierSymbolEntry(funcType, "getch", getLevel());
    se->SetSysFunc();
    install("getch", se);
    
    funcType = new FunctionType(TypeSystem::voidType, *paramsType);
    se = new IdentifierSymbolEntry(funcType, "putch", getLevel());
    se->SetSysFunc();
    install("putch", se);

    // Todo after add array
    se = new IdentifierSymbolEntry(funcType, "getarray", getLevel());
    se->SetSysFunc();
    install("getarray", se);

    se = new IdentifierSymbolEntry(funcType, "putarray", getLevel());
    se->SetSysFunc();
    install("putarray", se);
}

SymbolTable::SymbolTable(SymbolTable *prev)
{
    this->prev = prev;
    this->level = prev->level + 1;
}

/*
    Description: lookup the symbol entry of an identifier in the symbol table
    Parameters: 
        name: identifier name
    Return: pointer to the symbol entry of the identifier

    hint:
    1. The symbol table is a stack. The top of the stack contains symbol entries in the current scope.
    2. Search the entry in the current symbol table at first.
    3. If it's not in the current table, search it in previous ones(along the 'prev' link).
    4. If you find the entry, return it.
    5. If you can't find it in all symbol tables, return nullptr.
*/
SymbolEntry* SymbolTable::lookup(std::string name)
{
    // Todo
    map<string,SymbolEntry*>::iterator it;
    SymbolTable*p=this;
    it=p->symbolTable.find(name);
    while(it==p->symbolTable.end()&&p->level!=0)
    {
        p=p->prev;
        it=p->symbolTable.find(name);
    }
    if(it!=p->symbolTable.end())
    {
        return it->second;
    }
    else
        return nullptr;
}

// install the entry into current symbol table.
void SymbolTable::install(std::string name, SymbolEntry* entry)
{
    map<string,SymbolEntry*>::iterator it;
    it = symbolTable.find(name);
    if(it==symbolTable.end())
        symbolTable[name] = entry;
    else {
        cout<< name << " has been defined, please not define twice.\n";
        check = false;
    }
}

int SymbolTable::counter = 0;
static SymbolTable t;
SymbolTable *identifiers = &t;
SymbolTable *globals = &t;
