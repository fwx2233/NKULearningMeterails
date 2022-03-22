#ifndef __AST_H__
#define __AST_H__

#include <fstream>
#include "Type.h"

class SymbolEntry;

class Node
{
private:
    static int counter;
    int seq;
public:
    Node();
    int getSeq() const {return seq;};
    virtual void output(int level) = 0;
};

class ExprNode : public Node
{
protected:
    SymbolEntry *symbolEntry;
public:
    ExprNode(SymbolEntry *symbolEntry) : symbolEntry(symbolEntry){};
};


class UnaryExpr : public ExprNode
{
private:
    int op;
    ExprNode *expr;
public:
    enum{ADD,SUB,NOT,FUNC};
    UnaryExpr(SymbolEntry *se,int op ,ExprNode*expr):ExprNode(se),op(op),expr(expr){};
    void output(int level);
};

class BinaryExpr : public ExprNode
{
private:
    int op;
    ExprNode *expr1, *expr2;
public:
    enum {MUL,DIV,MOD,ADD, SUB, AND, OR, LESS,GREATER,EQUAL,NOTEQUAL, GREATEREQ,LESSEQ};
    BinaryExpr(SymbolEntry *se, int op, ExprNode*expr1, ExprNode*expr2) : ExprNode(se), op(op), expr1(expr1), expr2(expr2){};
    void output(int level);
};

class Constant : public ExprNode
{
public:
    Constant(SymbolEntry *se) : ExprNode(se){};
    void output(int level);
};

class Id : public ExprNode
{
public:
    Id(SymbolEntry *se) : ExprNode(se){};
    void output(int level);
};

class StmtNode : public Node
{};

class ExprStmt :public StmtNode
{
private:
    ExprNode* expr;
public:
    ExprStmt(ExprNode* expr):expr(expr){};
    void output(int level);
};

class CompoundStmt : public StmtNode
{
private:
    StmtNode *stmt;
public:
    CompoundStmt(StmtNode *stmt) : stmt(stmt) {};
    CompoundStmt() : stmt(0) {};
    void output(int level);
};

class SeqNode : public StmtNode
{
private:
    StmtNode *stmt1, *stmt2;
public:
    SeqNode(StmtNode *stmt1, StmtNode *stmt2) : stmt1(stmt1), stmt2(stmt2){};
    void output(int level);
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
};

class ConstDeclStmt:public DeclStmt
{
private:
    Defs* defs;
public:
    ConstDeclStmt(Defs* defs):defs(defs){};
    void output(int level);
};

class IfStmt : public StmtNode
{
private:
    ExprNode *cond;
    StmtNode *thenStmt;
public:
    IfStmt(ExprNode *cond, StmtNode *thenStmt) : cond(cond), thenStmt(thenStmt){};
    void output(int level);
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
};

class WhileStmt : public StmtNode
{
private:
    ExprNode *cond;
    StmtNode *dostmt;
public:
    WhileStmt(ExprNode *cond,StmtNode *dostmt):cond(cond),dostmt(dostmt){};
    void output(int level);
};

class ReturnStmt : public StmtNode
{
private:
    StmtNode *retStmt;
public:
    ReturnStmt(StmtNode*retValue) : retStmt(retValue) {};
    void output(int level);
};

class AssignStmt : public StmtNode
{
private:
    ExprNode *lval;
    ExprNode *expr;
public:
    AssignStmt(ExprNode *lval, ExprNode *expr) : lval(lval), expr(expr) {};
    void output(int level);
};

class FunctionDecl :public StmtNode
{
private:
    Id* id;
    StmtNode * parameters;
public:
    FunctionDecl(Id* id,StmtNode * parameters):id(id),parameters(parameters){};
    void output(int level);
};



class FunctionDef : public StmtNode
{
private:
    StmtNode *functiondecl;
    StmtNode *stmt;
public:
    FunctionDef(StmtNode* functiondecl, StmtNode *stmt) :functiondecl(functiondecl),stmt(stmt) {};
    void output(int level);
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
    void output(int level);
};



class funcCall : public ExprNode
{
private:
    SymbolEntry *se;
    ExprNode * params;
public:
    funcCall(SymbolEntry * se,ExprNode* params = nullptr): ExprNode(se),se(se), params(params){};
    void output(int level);
};

class funcCallStmt : public StmtNode
{
private:
    ExprNode *funccall;
public:
    funcCallStmt(ExprNode *funccall):funccall(funccall){};
    void output(int level);
};

class funcCallParas : public ExprNode
{
private:
    ExprNode* param;
    ExprNode* params;
public:
    funcCallParas(SymbolEntry* se,ExprNode* param, ExprNode* params): ExprNode(se),param(param), params(params){};
    void output(int level);
};

class funcCallPara : public ExprNode
{
    ExprNode* expr;
public:
    funcCallPara(SymbolEntry* se, ExprNode* expr) : ExprNode(se), expr(expr) {};
    void output(int level);
};

class OStreamFunction : public ExprNode
{
private:
    SymbolEntry* se;
    ExprNode* param;
    int type;
public:
    enum{PUTINT, PUTCH};
    OStreamFunction(SymbolEntry* se, ExprNode* param, int type) : ExprNode(se), se(se), param(param), type(type) {};
    void output(int level);
};
class IStreamFunction : public ExprNode
{
private:
    SymbolEntry* se;
    ExprNode* getint;
public:
    IStreamFunction(SymbolEntry* se, ExprNode* getint) : ExprNode(se), se(se), getint(getint) {};
    void output(int level);
};

class Ast
{
private:
    Node* root;
public:
    Ast() {root = nullptr;}
    void setRoot(Node*n) {root = n;}
    void output();
};

#endif
