%code top{
    #include <iostream>
    #include <assert.h>
    #include <string>
    #include "parser.h"
    extern Ast ast;
    int yylex();
    int yyerror( char const * );
    SymbolEntry *currentSe;
    SymbolEntry *currentRet=0;
    bool isReturn;
    int params=0;
}

%code requires {
    #include "Ast.h"
    #include "SymbolTable.h"
    #include "Type.h"
}

%union {
    int itype;
    char* strtype;
    StmtNode* stmttype;
    ExprNode* exprtype;
    Type* type;
    char chartype;
    Def* deftype;
    Defs* defstype;
}

%start Program
%token <strtype> ID PUTINT GETINT PUTCH
%token <itype> INTEGER
%token IF ELSE
%token WHILE
%token CONST
%token INT VOID
%token LPAREN RPAREN LBRACKT RBRACKT LBRACE RBRACE SEMICOLON
%token MUL DIV MOD ADD SUB OR AND LESS GREATER NOT EQUAL NOTEQUAL ASSIGN GREATEREQ LESSEQ
%token RETURN
%token COMMA

%nterm <deftype> VarDef ConstDef
%nterm <defstype> VarDefs ConstDefs
%nterm <stmttype> Stmts Stmt AssignStmt BlockStmt IfStmt ReturnStmt DeclStmt ConstDeclStmt VarDeclStmt FuncDef FuncParas FuncPara FuncDecl ExprStmt WhileStmt FuncCallParas FuncCallPara
%nterm <exprtype> Exp AddExp Cond LOrExp PrimaryExp LVal RelExp LAndExp UnaryExp MulExp EqExp InitVal FuncCall  IOStream PutStream GetStream
%nterm <type> Type
%nterm <chartype> UnaryOp

%precedence THEN
%precedence ELSE
%%
Program
    : Stmts {
        ast.setRoot($1);
    }
    ;
Stmts
    : Stmt {$$=$1;}
    | Stmts Stmt{
        $$ = new SeqNode($1, $2);
    }
    ;
Stmt
    : AssignStmt {$$=$1;}
    | BlockStmt {$$=$1;}
    | IfStmt {$$=$1;}
    | ReturnStmt {$$=$1;}
    | DeclStmt {$$=$1;}
    | FuncDef {$$=$1;}
    | FuncDecl SEMICOLON {$$=$1;}
    | ExprStmt {$$=$1;}
    | WhileStmt {$$=$1;}
    ;
LVal
    : ID {
        SymbolEntry *se;
        se = identifiers->lookup($1);
        if(se == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)$1);
            delete [](char*)$1;
            assert(se != nullptr);
        }
        /*Id* tempid;
        if(dynamic_cast<IdentifierSymbolEntry*>(se)->isParam()||dynamic_cast<IdentifierSymbolEntry*>(se)->isGlobal())
        {
            tempid=dynamic_cast<IdentifierSymbolEntry*>(se)->getTempReg();
        }
        else
        {
            tempid=new Id(se);
        }*/
        $$ = new Id(se);
        delete []$1;
    }
    ;
AssignStmt
    :
    LVal ASSIGN Exp SEMICOLON {
        $$ = new AssignStmt($1, $3);
    }
    ;
BlockStmt
    :   LBRACE 
        {identifiers = new SymbolTable(identifiers);} 
        Stmts RBRACE 
        {
            $$ = new CompoundStmt($3);
            SymbolTable *top = identifiers;
            identifiers = identifiers->getPrev();
            delete top;
        }
        |
        LBRACE RBRACE
        {
            $$= new CompoundStmt();
        }
    ;
IfStmt
    : IF LPAREN Cond RPAREN Stmt %prec THEN {
        $$ = new IfStmt($3, $5);
    }
    | IF LPAREN Cond RPAREN Stmt ELSE Stmt {
        $$ = new IfElseStmt($3, $5, $7);
    }
    ;
WhileStmt
    :
    WHILE LPAREN Cond RPAREN Stmt
    {
        $$= new WhileStmt($3,$5);
    }
ReturnStmt
    :
    RETURN Exp SEMICOLON{
        $$ = new ReturnStmt($2);
        currentRet=$2->getSymPtr();
        isReturn=1;
    }
    |
    RETURN SEMICOLON{
        $$ = new ReturnStmt;
        isReturn=1;
    }
    ;
Exp
    :
    AddExp {$$ = $1;}
    ;

ExprStmt
    :
    Exp SEMICOLON
    {
        $$=new ExprStmt($1);
    }
    |
    SEMICOLON
    {
        $$=new ExprStmt(nullptr);
    }
    ;

Cond
    :
    LOrExp {$$ = $1;}
    ;
PrimaryExp
    :
    LVal {
        $$ = $1;
    }
    | INTEGER {
        SymbolEntry *se = new ConstantSymbolEntry(TypeSystem::intType, $1);
        $$ = new Constant(se);
    }
    | LPAREN Exp RPAREN {
        $$ = $2;
    }
    ;
UnaryOp
    :
    ADD
    {
        $$='+';
    }
    |
    SUB
    {
        $$='-';
    }
    |
    NOT
    {
        $$='!';
    }
    ;
UnaryExp
    :
    PrimaryExp {$$=$1;}
    |
    FuncCall
    {
	    SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
	    $$ = new UnaryExpr(se, UnaryExpr::FUNC, $1);
    }
    |
    IOStream {$$ = $1;}
    |
    UnaryOp UnaryExp {
        SymbolEntry*se=new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        int op;
        switch($1)
        {
            case '+' :
                op = UnaryExpr::ADD;
                break;
            case '-' :
                op = UnaryExpr::SUB;
                break;
            case '!' :
                op = UnaryExpr::NOT;
                break;
        }
        $$ = new UnaryExpr(se, op , $2);
    }
    ;
MulExp
    :
    UnaryExp {$$ = $1;}
    |
    MulExp MUL UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MUL, $1, $3);   
    }
    |
    MulExp DIV UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::DIV, $1, $3);   
    }
    |
    MulExp MOD UnaryExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::MOD, $1, $3);   
    }
    ;
AddExp
    :
    MulExp {$$ = $1;}
    |
    AddExp ADD MulExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::ADD, $1, $3);
    }
    |
    AddExp SUB MulExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::SUB, $1, $3);
    }
    ;
RelExp
    :
    AddExp {$$ = $1;}
    |
    RelExp LESS AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LESS, $1, $3);
    }
    |
    RelExp GREATER AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::GREATER, $1, $3);
    }
    |
    RelExp NOTEQUAL AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::NOTEQUAL, $1, $3); 
    }
    |
    RelExp GREATEREQ AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::GREATEREQ, $1, $3); 
    }
    |
    RelExp LESSEQ AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LESSEQ, $1, $3); 
    }
    ;
EqExp
    :
    RelExp {$$=$1;}
    |
    EqExp EQUAL RelExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::EQUAL, $1, $3);      
    }
    ;
LAndExp
    :
    EqExp {$$ = $1;}
    |
    LAndExp AND EqExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::AND, $1, $3);
    }
    ;
LOrExp
    :
    LAndExp {$$ = $1;}
    |
    LOrExp OR LAndExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::OR, $1, $3);
    }
    ;
InitVal
    :
    Exp {$$=$1;}
    ;
Type
    : INT {
        $$ = TypeSystem::intType;
    }
    | VOID {
        $$ = TypeSystem::voidType;
    }
    ;
DeclStmt
    : 
    VarDeclStmt {
        $$=$1;
    }
    |
    ConstDeclStmt {
        $$=$1;
    }
    ;
VarDef
    :
    ID
    {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        dynamic_cast<IdentifierSymbolEntry*>(se)->setvar();
        identifiers->install($1, se);
        Id* tempid=new Id(se);
        if(dynamic_cast<IdentifierSymbolEntry*>(se)->isGlobal())
        {
            dynamic_cast<IdentifierSymbolEntry*>(se)->setTempReg(tempid);
        }
        $$=new Def(tempid);
        delete []$1;
    }
    |
    ID ASSIGN InitVal
    {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        dynamic_cast<IdentifierSymbolEntry*>(se)->setvar();
        identifiers->install($1, se);
        Id* tempid=new Id(se);
        if(dynamic_cast<IdentifierSymbolEntry*>(se)->isGlobal())
        {
            dynamic_cast<IdentifierSymbolEntry*>(se)->setTempReg(tempid);
        }
        $$=new Def(tempid,$3);
        delete []$1;
    }
    ;
VarDefs
    :
    VarDef COMMA VarDefs
    {
        $$=new Defs($1,$3);
    }
    |
    VarDef
    {
        $$=new Defs($1);
    }
    ;
ConstDef
    :
    ID ASSIGN InitVal
    {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        dynamic_cast<IdentifierSymbolEntry*>(se)->setcon();
        identifiers->install($1, se);
        Id* tempid=new Id(se);
        if(dynamic_cast<IdentifierSymbolEntry*>(se)->isGlobal())
        {
            dynamic_cast<IdentifierSymbolEntry*>(se)->setTempReg(tempid);
        }
        $$=new Def(tempid,$3);
        delete []$1;
    }
    ;

ConstDefs
    :
    ConstDef COMMA ConstDefs
    {
        $$=new Defs($1,$3);
    }
    |
    ConstDef
    {
        $$=new Defs($1);
    }

ConstDeclStmt
    :
    CONST Type ConstDefs SEMICOLON{
        $$=new ConstDeclStmt($3);
    }
    ;

VarDeclStmt
    :
    Type VarDefs SEMICOLON {
        $$=new VarDeclStmt($2);
    }
    ;

FuncDecl
    :
    Type ID 
    LPAREN 
    {       
        identifiers = new SymbolTable(identifiers);
    }
    RPAREN
    {
        string funcname;
        funcname=$2;
        if(funcname!="main")
        {
            funcname+='0';
        }
        SymbolTable*p=identifiers->getPrev();
        Type *funcType;
        funcType = new FunctionType($1,{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType,funcname.c_str(), p->getLevel());
        currentSe = se;
        p->install(funcname.c_str(),se);
        $$=new FunctionDecl(new Id(currentSe),0);
        delete []$2;
        params=0;
    }
    |
    Type ID LPAREN 
    {    
        identifiers = new SymbolTable(identifiers);
    }
    FuncParas RPAREN
    {
        string funcname;
        funcname=$2;
        funcname+=params+'0';
        SymbolTable*p=identifiers->getPrev();
        Type *funcType;
        funcType = new FunctionType($1,{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, funcname.c_str(), p->getLevel());
        currentSe = se;
        p->install(funcname.c_str(),se);
        $$=new FunctionDecl(new Id(currentSe),$5);
        delete []$2;
        params=0;
    }
    ;

FuncDef
    :
    FuncDecl BlockStmt {
        $$=new FunctionDef($1,$2);
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        dynamic_cast<FunctionType*>(dynamic_cast<FunctionDecl*>(dynamic_cast<FunctionDef*>($$)->getdecl())->getid()->getSymPtr()->getType())->setReturn(currentRet);
        dynamic_cast<FunctionType*>(dynamic_cast<FunctionDecl*>(dynamic_cast<FunctionDef*>($$)->getdecl())->getid()->getSymPtr()->getType())->setisret(isReturn);
        currentRet=0;
        isReturn=0;
    }
    ;

FuncParas
    :
    FuncPara COMMA FuncParas {
        $$ = new funcParams($1, $3);
    }
    |
    FuncPara {
        $$ =new funcParams($1);
    }
    ;

FuncPara
    :
    Type ID ASSIGN Exp{
        params++;
        SymbolEntry *se;
        se = new IdentifierSymbolEntry($1, $2, identifiers->getLevel());
        identifiers->install($2, se);
        Id* tempid=new Id(se);
        dynamic_cast<IdentifierSymbolEntry*>(se)->setTempReg(tempid);
        $$ = new funcParam(tempid, $4,$1);
        delete []$2;
    }
    |
    Type ID {
        params++;
        SymbolEntry *se;
        se = new IdentifierSymbolEntry($1, $2, identifiers->getLevel());
        identifiers->install($2, se);
        Id* tempid=new Id(se);
        dynamic_cast<IdentifierSymbolEntry*>(se)->setTempReg(tempid);
        $$ = new funcParam(tempid,$1);
        delete []$2;
    }
    |
    Type {
        params++;
        $$=new funcParam(0,0,$1);
    }
    ;

FuncCall
    :
    ID LPAREN FuncCallParas RPAREN {
        string funcname=$1;
        if(funcname!="putint"&&funcname!="getint"&&funcname!="getch"&&funcname!="putch"&&funcname!="getarray"&&funcname!="putarray")
            funcname+=params+'0';
        SymbolEntry* se = identifiers->lookup(funcname.c_str());
        if(se == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", funcname.c_str());
            delete [](char*)$1;
            assert(se != nullptr);
        }
        
        SymbolEntry* thisSe= new IdentifierSymbolEntry(dynamic_cast<FunctionType*>(se->getType())->getRetType(), funcname.c_str(), identifiers->getLevel());
        $$ = new funcCall(se,thisSe,$3);
        params=0;
    }
    |
    ID LPAREN RPAREN {
        string funcname=$1;
        if(funcname!="putint"&&funcname!="getint"&&funcname!="getch"&&funcname!="putch"&&funcname!="getarray"&&funcname!="putarray")
            funcname+=params+'0';
        SymbolEntry* se = identifiers->lookup(funcname.c_str());
        if(se == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", funcname.c_str());
            delete [](char*)$1;
            assert(se != nullptr);
        }
        
        SymbolEntry* thisSe= new IdentifierSymbolEntry(dynamic_cast<FunctionType*>(se->getType())->getRetType(),funcname.c_str(), identifiers->getLevel());
        $$ = new funcCall(se,thisSe,nullptr);
        params =0;
    }
    ;

FuncCallParas
    :
    FuncCallPara COMMA FuncCallParas {
        $$ = new funcCallParas($1, $3);
    }
    |
    FuncCallPara {
        $$ = new funcCallParas($1);
    }
    ; 

FuncCallPara
    :
    Exp {
        params++;
        $$ = new funcCallPara( $1);
    }
    ;

IOStream
    :
    PutStream {
        $$ = $1;
    }
    |
    GetStream {
        $$ = $1;
    }
    ;

PutStream
    :
    PUTINT LPAREN FuncCallPara RPAREN {
        SymbolEntry* se = identifiers->lookup($1);
        $$ = new OStreamFunction(se, $3, 0);

    }
    |
    PUTCH LPAREN FuncCallPara RPAREN {
        SymbolEntry* se = identifiers->lookup($1);
        $$ = new OStreamFunction(se, $3, 1);
    }
    ;

GetStream
    :
    GETINT LPAREN RPAREN{
        SymbolEntry* se = identifiers->lookup($1);
        $$ = new IStreamFunction(se, nullptr);
    }
    ;

%%

int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
