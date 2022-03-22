%code top{
    #include <iostream>
    #include <assert.h>
    #include "parser.h"
    extern Ast ast;
    int yylex();
    int yyerror( char const * );
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
%nterm <stmttype> Stmts Stmt AssignStmt BlockStmt IfStmt ReturnStmt DeclStmt ConstDeclStmt VarDeclStmt FuncDef FuncParas FuncPara FuncDecl ExprStmt WhileStmt 
%nterm <exprtype> Exp AddExp Cond LOrExp PrimaryExp LVal RelExp LAndExp UnaryExp MulExp EqExp InitVal FuncCall FuncCallParas FuncCallPara IOStream PutStream GetStream
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
    | Stmt Stmts{
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
    RETURN ExprStmt{
        $$ = new ReturnStmt($2);
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
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::LESS, $1, $3);
    }
    |
    RelExp GREATER AddExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::GREATER, $1, $3);
    }
    ;
EqExp
    :
    RelExp {$$=$1;}
    |
    EqExp EQUAL RelExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::EQUAL, $1, $3);      
    }
    |
    EqExp NOTEQUAL RelExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::NOTEQUAL, $1, $3); 
    }
    |
    EqExp GREATEREQ RelExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::NOTEQUAL, $1, $3); 
    }
    |
    EqExp LESSEQ RelExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::NOTEQUAL, $1, $3); 
    }
    ;
LAndExp
    :
    EqExp {$$ = $1;}
    |
    LAndExp AND EqExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new BinaryExpr(se, BinaryExpr::AND, $1, $3);
    }
    ;
LOrExp
    :
    LAndExp {$$ = $1;}
    |
    LOrExp OR LAndExp
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
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
        identifiers->install($1, se);
        $$=new Def(new Id(se));
        delete []$1;
    }
    |
    ID ASSIGN InitVal
    {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, $1, identifiers->getLevel());
        identifiers->install($1, se);
        $$=new Def(new Id(se),$3);
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
        identifiers->install($1, se);
        $$=new Def(new Id(se),$3);
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
    Type ID LPAREN RPAREN
    {
        Type *funcType;
        funcType = new FunctionType($1,{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, $2, identifiers->getLevel());
        identifiers->install($2,se);
        $$=new FunctionDecl(new Id(se),0);
        delete []$2;
    }
    |
    Type ID LPAREN FuncParas RPAREN
    {
        Type *funcType;
        funcType = new FunctionType($1,{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, $2, identifiers->getLevel());
        identifiers->install($2,se);
        $$=new FunctionDecl(new Id(se),$4);
        delete []$2;
    }
    ;

FuncDef
    :
    FuncDecl BlockStmt {
        $$=new FunctionDef($1,$2);
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
        SymbolEntry *se;
        se = new IdentifierSymbolEntry($1, $2, identifiers->getLevel());
        identifiers->install($2, se);
        $$ = new funcParam(new Id(se), $4,0);
        delete []$2;
    }
    |
    Type ID {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry($1, $2, identifiers->getLevel());
        identifiers->install($2, se);
        $$ = new funcParam(new Id(se),0,0);
        delete []$2;
    }
    |
    Type {
        $$=new funcParam(0,0,$1);
    }
    ;

FuncCall
    :
    ID LPAREN FuncCallParas RPAREN {
        SymbolEntry* se = identifiers->lookup($1);
        $$ = new funcCall(se, $3);
    }
    |
    ID LPAREN RPAREN {
        SymbolEntry* se = identifiers->lookup($1);
        $$ = new funcCall(se, nullptr);
    }
    ;

FuncCallParas
    :
    FuncCallPara COMMA FuncCallParas {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new funcCallParas(se, $1, $3);
    }
    |
    FuncCallPara {
        $$ = $1;
    }
    ; 

FuncCallPara
    :
    Exp {
        SymbolEntry* se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        $$ = new funcCallPara(se, $1);
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
