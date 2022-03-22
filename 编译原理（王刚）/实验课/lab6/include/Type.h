#ifndef __TYPE_H__
#define __TYPE_H__
#include <vector>
#include <string>
class SymbolEntry;

class Type
{
private:
    int kind;
protected:
    enum {INT, VOID, FUNC, PTR};
public:
    Type(int kind) : kind(kind) {};
    virtual ~Type() {};
    virtual std::string toStr() = 0;
    bool isInt() const {return kind == INT;};
    bool isVoid() const {return kind == VOID;};
    bool isFunc() const {return kind == FUNC;};
};

class IntType : public Type
{
private:
    int size;
public:
    IntType(int size) : Type(Type::INT), size(size){};
    std::string toStr();
};

class VoidType : public Type
{
public:
    VoidType() : Type(Type::VOID){};
    std::string toStr();
};

class FunctionType : public Type
{
private:
    Type *returnType;
    std::vector<Type*> paramsType;
    int isReturned = 0;
    bool isret=0;
    SymbolEntry* returnEntry=0;
public:
    FunctionType(Type* returnType, std::vector<Type*> paramsType) : 
    Type(Type::FUNC), returnType(returnType), paramsType(paramsType){};
    Type* getRetType() {return returnType;};
    std::vector<Type*>* getParams(){return &paramsType;};
    int getNumOfParas() {return paramsType.size();}
    void addParaType(Type* paraType) {this->paramsType.push_back(paraType);}
    int isReturn() {return isReturned;}
    bool IsRet(){return isret;};
    void setReturn(SymbolEntry* returnEntry) {this->returnEntry=returnEntry;if(returnEntry)this->isReturned=1;}
    void rmReturn(){this->returnEntry=0;this->isReturned=0;}
    void setisret(bool isret){this->isret=isret;};
    std::string toStr();
};

class PointerType : public Type
{
private:
    Type *valueType;
public:
    PointerType(Type* valueType) : Type(Type::PTR) {this->valueType = valueType;};
    std::string toStr();
};

class TypeSystem
{
private:
    static IntType commonInt;
    static IntType commonBool;
    static VoidType commonVoid;
public:
    static Type *intType;
    static Type *voidType;
    static Type *boolType;
};

#endif
