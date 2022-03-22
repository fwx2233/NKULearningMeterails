#include "Ast.h"
#include "SymbolTable.h"
#include <string>
#include "Type.h"
using namespace std;

extern FILE *yyout;
int Node::counter = 0;

Node::Node()
{
    seq = counter++;
}

void Ast::output()
{
    fprintf(yyout, "program\n");
    if(root != nullptr)
        root->output(4); 
}

void UnaryExpr::output(int level)
{
    string op_str;
    switch(op)
    {
        case ADD:
            op_str = "plus";
            break;
        case SUB:
            op_str = "minus";
            break;
        case NOT:
            op_str = "not";
            break;
        case FUNC:
            op_str = "func";
            break;
        
    }
    fprintf(yyout, "%*cUnaryExpr\top: %s\n", level, ' ', op_str.c_str());
    expr->output(level + 4);
}

void BinaryExpr::output(int level)
{
    std::string op_str;
    switch(op)
    {
        case ADD:
            op_str = "add";
            break;
        case SUB:
            op_str = "sub";
            break;
        case AND:
            op_str = "and";
            break;
        case OR:
            op_str = "or";
            break;
        case LESS:
            op_str = "less";
            break;
        case GREATER:
            op_str = "greater";
            break;
        case EQUAL:
            op_str = "equal";
            break;  
        case NOTEQUAL:
            op_str = "notequal";
            break; 
        case MUL:
            op_str = "mul";
            break;
        case MOD:
            op_str = "mod";
            break;
        case DIV:
            op_str = "div";
            break;
        case GREATEREQ:
            op_str = "greatereq";
            break;
        case LESSEQ:
            op_str = "lesseq";
            break;
    }
    fprintf(yyout, "%*cBinaryExpr\top: %s\n", level, ' ', op_str.c_str());
    expr1->output(level + 4);
    expr2->output(level + 4);
}

void Constant::output(int level)
{
    std::string type, value;
    type = symbolEntry->getType()->toStr();
    value = symbolEntry->toStr();
    fprintf(yyout, "%*cIntegerLiteral\tvalue: %s\ttype: %s\n", level, ' ',
            value.c_str(), type.c_str());
}

void Id::output(int level)
{
    std::string name, type;
    int scope;
    name = symbolEntry->toStr();
    type = symbolEntry->getType()->toStr();
    scope = dynamic_cast<IdentifierSymbolEntry*>(symbolEntry)->getScope();
    fprintf(yyout, "%*cId\tname: %s\tscope: %d\ttype: %s\n", level, ' ',
            name.c_str(), scope, type.c_str());
}

void ExprStmt::output(int level)
{
    fprintf(yyout, "%*cExprStmt\n", level, ' ');
    if(expr!=NULL){
        expr->output(level+4);
    }
}

void CompoundStmt::output(int level)
{

    fprintf(yyout, "%*cCompoundStmt\n", level, ' ');
    if(stmt==0)
        return;
    stmt->output(level + 4);
}

void SeqNode::output(int level)
{
    fprintf(yyout, "%*cSequence\n", level, ' ');
    stmt1->output(level + 4);
    stmt2->output(level + 4);
}

void Def::output(int level)
{
    fprintf(yyout, "%*cDefStmt\n", level, ' ');
    id->output(level + 4);
    if(expr!=0)
    expr->output(level + 4);
}

void Defs::output(int level)
{
    def->output(level);
    if(defs!=0)
    defs->output(level);
}

void VarDeclStmt::output(int level)
{
    fprintf(yyout,"%*cVarDeclStmt\n", level, ' ');
    defs->output(level+4);
}

void ConstDeclStmt::output(int level)
{
    fprintf(yyout,"%*cConstDeclStmt\n", level, ' ');
    defs->output(level+4);
}

void IfStmt::output(int level)
{
    fprintf(yyout, "%*cIfStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
}

void IfElseStmt::output(int level)
{
    fprintf(yyout, "%*cIfElseStmt\n", level, ' ');
    cond->output(level + 4);
    thenStmt->output(level + 4);
    elseStmt->output(level + 4);
}

void WhileStmt:: output(int level)
{
    fprintf(yyout, "%*cWhileStmt\n", level, ' ');
    cond->output(level + 4);
    dostmt->output(level + 4);
}

void ReturnStmt::output(int level)
{
    fprintf(yyout, "%*cReturnStmt\n", level, ' ');
    retStmt->output(level + 4);
}

void AssignStmt::output(int level)
{
    fprintf(yyout, "%*cAssignStmt\n", level, ' ');
    lval->output(level + 4);
    expr->output(level + 4);
}

void FunctionDecl::output(int level)
{
    fprintf(yyout, "%*cFunctionDecl\n", level, ' ');
    id->output(level+4);
    if(parameters!=0)
        parameters->output(level + 4);
    else
    {
        fprintf(yyout,"%*cvoid parameters\n", level+4, ' ');
    }
}

void FunctionDef::output(int level)
{
    fprintf(yyout, "%*cFunctionDef\n", level, ' ');
    functiondecl->output(level+4);
    stmt->output(level+4);
}

void funcParams::output(int level)
{

    param->output(level);
    if(params!=0)
        params->output(level);

}

void funcParam::output(int level)
{

    fprintf(yyout, "%*cFunctionDeclareParam\n", level, ' ');
    if(type==0)
    {
        id->output(level + 4);
        if(expr != nullptr)
        expr->output(level + 4); 
    }
    else
    {
        if(type->isInt())
        {
            fprintf(yyout, "%*cparatype:%s\n", level, ' ',"int");
        }
    }
}

void funcCall::output(int level)
{
    std::string name, type;
    name = se->toStr();
    type = se->getType()->toStr();
    fprintf(yyout, "%*cFunctionCall  funtion name: %s,  type: %s\n",level, ' ',name.c_str(),type.c_str());
    if(params != nullptr)
        params->output(level + 4);
}

void funcCallStmt::output(int level)
{
    fprintf(yyout, "%*cFuncCallStmt\n", level, ' ');
    funccall->output(level + 4);
}
void funcCallParas::output(int level)
{
    fprintf(yyout, "%*cFunctionCallParams\n", level, ' ');
    param->output(level + 4);
    params->output(level + 4);
}

void funcCallPara::output(int level)
{
    fprintf(yyout, "%*cFunctionCallParam\n", level, ' ');
    if(expr)
        expr->output(level + 4);
}

void OStreamFunction::output(int level)
{
    std::string name;
    switch (type)
    {
    case PUTINT:
        name = "putint";
        break;
    case PUTCH:
        name = "putch";
        break;
    }
    fprintf(yyout, "%*cIOFunctionCall  funtion name: %s,  type: %s\n",level, ' ',name.c_str(), "void");
    if(param != nullptr)
        param->output(level + 4);
}

void IStreamFunction::output(int level)
{
    std::string name, type;
    name = "getint";
    type = "int";
    fprintf(yyout, "%*cIOFunctionCall  funtion name: %s,  type: %s\n",level, ' ',name.c_str(),type.c_str());
   // getint->output(level+4);
}