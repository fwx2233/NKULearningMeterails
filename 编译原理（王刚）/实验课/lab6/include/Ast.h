#ifndef __AST_H__
#define __AST_H__

#include <fstream>
#include <string>
#include "Operand.h"

class SymbolEntry;
class Unit;
class Function;
class BasicBlock;
class Instruction;
class IRBuilder;
extern bool check;

class Node
{
private:
    static int counter;
    int seq;
protected:
    std::vector<Instruction*> true_list;
    std::vector<Instruction*> false_list;
    static IRBuilder *builder;
    void backPatch(std::vector<Instruction*> &list, BasicBlock*bb);
    void backPatchFalse(std::vector<Instruction*> &list, BasicBlock* bb);
    std::vector<Instruction*> merge(std::vector<Instruction*> &list1, std::vector<Instruction*> &list2);

public:
    Node();
    int getSeq() const {return seq;};
    static void setIRBuilder(IRBuilder*ib) {builder = ib;};
    virtual void output(int level) = 0;
    virtual void typeCheck(int level) = 0;
    virtual void genCode() = 0;
    std::vector<Instruction*>& trueList() {return true_list;}
    std::vector<Instruction*>& falseList() {return false_list;}
};

class ExprNode : public Node
{
protected:
    SymbolEntry *symbolEntry;
    Operand *dst;   // The result of the subtree is stored into dst.
    bool isCond=0;
    bool isFir=1;
public:
    ExprNode(SymbolEntry *symbolEntry) : symbolEntry(symbolEntry){dst = new Operand(symbolEntry);};
    Operand* getOperand() {return dst;};
    void setOperand(Operand* op){dst=op;};    
    SymbolEntry* getSymPtr() {return symbolEntry;};
    bool IsCond(){return isCond;}
    bool IsFir(){return isFir;};
    void setnotfir(){isFir=0;};
};

class UnaryExpr : public ExprNode
{
private:
    int op;
    ExprNode *expr;
public:
    enum{ADD,SUB,NOT,FUNC};
    UnaryExpr(SymbolEntry *se,int op ,ExprNode*expr):ExprNode(se),op(op),expr(expr){dst = new Operand(se);};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};


class BinaryExpr : public ExprNode
{
private:
    int op;
    ExprNode *expr1, *expr2;
public:
    enum {MUL,DIV,MOD,ADD, SUB, AND, OR, LESS,GREATER,EQUAL,NOTEQUAL, GREATEREQ,LESSEQ};
    BinaryExpr(SymbolEntry *se, int op, ExprNode*expr1, ExprNode*expr2) : ExprNode(se), op(op), expr1(expr1), expr2(expr2){dst = new Operand(se);if(op>=AND)isCond=true;};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};

class Constant : public ExprNode
{
public:
    Constant(SymbolEntry *se) : ExprNode(se){dst = new Operand(se);};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};

class Id : public ExprNode
{
public:
    Id(SymbolEntry *se);
    void output(int level);
    void typeCheck(int level);
    void genCode();
};

class StmtNode : public Node
{
    bool isinfunc=false;
    SymbolEntry* parent=0;
    bool isincircle=false;
public:
    bool getisinfunc(){return isinfunc;};
    bool getisincircle(){return isincircle;};
    SymbolEntry* getparent(){return parent;}
    void setisinfunc(SymbolEntry* parent){isinfunc=true;this->parent=parent;};
    void setisincircle(){isincircle=true;};
    void checkisinfunc();
};


class ExprStmt :public StmtNode
{
private:
    ExprNode* expr;
public:
    ExprStmt(ExprNode* expr):expr(expr){};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};

class CompoundStmt : public StmtNode
{
private:
    StmtNode *stmt;
public:
    CompoundStmt(StmtNode *stmt) : stmt(stmt) {};
    CompoundStmt() : stmt(0) {};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};

class SeqNode : public StmtNode
{
private:
    StmtNode *stmt1, *stmt2;
public:
    SeqNode(StmtNode *stmt1, StmtNode *stmt2) : stmt1(stmt1), stmt2(stmt2){};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};


class Def:public StmtNode
{
private:
    Id* id;
    ExprNode* expr;
public:
    Def(Id* id):id(id),expr(0){};
    Def(Id* id,ExprNode* expr):id(id),expr(expr){};
    void output(int level);
    void typeCheck(int level);
    void genCode();
    bool isConst();
};

class Defs:public StmtNode
{
private:
    Def* def;
    Defs* defs;
public:
    Defs(Def* def,Defs* defs):def(def),defs(defs){};
    Defs(Def* def):def(def),defs(0){};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};

class DeclStmt:public StmtNode
{};

class VarDeclStmt : public DeclStmt
{
private:
    Defs* defs;
public:
    VarDeclStmt(Defs* defs):defs(defs){};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};

class ConstDeclStmt:public DeclStmt
{
private:
    Defs* defs;
public:
    ConstDeclStmt(Defs* defs):defs(defs){};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};

class IfStmt : public StmtNode
{
private:
    ExprNode *cond;
    StmtNode *thenStmt;
public:
    IfStmt(ExprNode *cond, StmtNode *thenStmt) : cond(cond), thenStmt(thenStmt){};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};

class IfElseStmt : public StmtNode
{
private:
    ExprNode *cond;
    StmtNode *thenStmt;
    StmtNode *elseStmt;
public:
    IfElseStmt(ExprNode *cond, StmtNode *thenStmt, StmtNode *elseStmt) : cond(cond), thenStmt(thenStmt), elseStmt(elseStmt) {};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};
class WhileStmt : public StmtNode
{
private:
    ExprNode *cond;
    StmtNode *dostmt;
public:
    WhileStmt(ExprNode *cond,StmtNode *dostmt):cond(cond),dostmt(dostmt){};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};


class ReturnStmt : public StmtNode
{
private:
    ExprNode *retValue;
public:
    ReturnStmt(ExprNode*retValue=0) : retValue(retValue) {};
    void output(int level);
    void typeCheck(int level);
    void genCode();
    ExprNode *getret(){return retValue;};
};

class AssignStmt : public StmtNode
{
private:
    ExprNode *lval;
    ExprNode *expr;
public:
    AssignStmt(ExprNode *lval, ExprNode *expr) : lval(lval), expr(expr) {};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};

class FunctionDecl :public StmtNode
{
private:
    Id* id;
    StmtNode * parameters;
public:
    FunctionDecl(Id* id,StmtNode * parameters):id(id),parameters(parameters){};
    void output(int level);
    void typeCheck(int level);
    void genCode();
    SymbolEntry*getSe(){return id->getSymPtr();};
    Id* getid(){return id;};
    
};

class FunctionDef : public StmtNode
{
private:
    StmtNode *functiondecl;
    StmtNode *stmt;
public:
    FunctionDef(StmtNode* functiondecl, StmtNode *stmt) :functiondecl(functiondecl),stmt(stmt) {};
    void output(int level);
    void typeCheck(int level);
    void genCode();
    StmtNode* getdecl(){return functiondecl;};
};


class funcParams: public StmtNode
{
// a class for storing parameters in function declare
private:
    StmtNode* param;
    StmtNode* params;
public:
    funcParams(StmtNode *param, StmtNode *params) : param(param), params(params){};
    funcParams(StmtNode *param) : param(param), params(0){};
    void output(int level);
    void typeCheck(int level);
    void genCode();
    StmtNode* getFirstParam(){return param;};
    StmtNode* getNextParam(){return params;};
};


class funcParam : public StmtNode
// a class for parameter
{
private:
    Id *id=0;
    ExprNode *expr=0;
    Type *type=0;
public:
    funcParam(Id *id,ExprNode *expr,Type* type) : id(id), expr(expr),type(type) {};
    funcParam(Id *id,Type* type) : id(id),type(type) {};
    void output(int level);
    void typeCheck(int level);
    void genCode();
    ExprNode* getExpr(){return expr;};
    Id* getId(){return id;};
    Type* getType(){return type;};
};



class funcCall : public ExprNode
{
private:
    
    Id*id;
    StmtNode * params;
    SymbolEntry *thisSe;
public:
    funcCall(SymbolEntry * se,SymbolEntry *thisSe,StmtNode* params = nullptr):ExprNode(se),thisSe(thisSe),params(params) {id=new Id(thisSe);};
    void output(int level);
    void typeCheck(int level);
    void genCode();
    Operand* getOperand(){return id->getOperand();};
    bool IsCall=1;
};

class funcCallStmt : public StmtNode
{
private:
    ExprNode *funccall;
public:
    funcCallStmt(ExprNode *funccall):funccall(funccall){};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};
class funcCallParas: public StmtNode
{
// a class for storing parameters in function declare
private:
    StmtNode* param;
    StmtNode* params;
public:
    funcCallParas(StmtNode *param, StmtNode *params) : param(param), params(params){};
    funcCallParas(StmtNode *param) : param(param), params(0){};
    void output(int level);
    void typeCheck(int level);
    void genCode();
    StmtNode* getNextParam(){return params;};
    StmtNode* getFirstParam(){return param;};
};


class funcCallPara : public StmtNode
{
    ExprNode* expr;
public:
    funcCallPara(ExprNode* expr) :  expr(expr) {};
    void output(int level);
    void typeCheck(int level);
    void genCode();
    ExprNode* getParam() {return expr;};
};

class OStreamFunction : public ExprNode
{
private:
    SymbolEntry* se;
    StmtNode* param;
    int type;
public:
    enum{PUTINT, PUTCH};
    OStreamFunction(SymbolEntry* se, StmtNode* param, int type) : ExprNode(se), se(se), param(param), type(type) {};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};
class IStreamFunction : public ExprNode
{
private:
    SymbolEntry* se;
    ExprNode* getint;
public:
    IStreamFunction(SymbolEntry* se, ExprNode* getint) : ExprNode(se), se(se), getint(getint) {};
    void output(int level);
    void typeCheck(int level);
    void genCode();
};




class Ast
{
private:
    Node* root;
public:
    Ast() {root = nullptr;}
    void setRoot(Node*n) {root = n;}
    void output();
    void typeCheck();
    void genCode(Unit *unit);
};

#endif
