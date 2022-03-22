%option noyywrap
%option yylineno
%{
    /*
    * You will need to comment this line in lab5.
    */
    #define ONLY_FOR_LEX
    
    #ifdef ONLY_FOR_LEX
    
    #else
    #define YYSTYPE void *
    #include "parser.h"
    #endif

    #define YY_NO_UNPUT
    #define YY_NO_INPUT
    #include <string>

    //#ifdef ONLY_FOR_LEX
    #include <ostream>
    #include <fstream>
    #include <vector>
    #include <sstream>
    #include <map>
    #include <iomanip>
    using namespace std;
    extern FILE *yyin; 
    extern FILE *yyout;
    std::ifstream input("./testin");
    std::ofstream output("./testout");
    struct ScopeNode
    {
        ScopeNode*father;
    };

    struct Symbol
    {
        string token;
        string lexeme;
        int lineno;
        // flag==0:10进制, flag==1:8进制; flag==2:16进制
        int flag=0;
        ScopeNode* now_scope=0;
    };



    class SymbolTable
    {
        vector<Symbol> SymbolList;
        ScopeNode* ThisScope;
        public:
        SymbolTable()
        {
            ThisScope=new ScopeNode;
            ThisScope->father=0;
        }

        void AddSymbol(string Token,string Lexeme,int Lineno, int flag=0)
        {
            Symbol newSymbol={Token,Lexeme,Lineno};
            newSymbol.flag=flag;
            if(Token=="ID")
            {
                newSymbol.now_scope=ThisScope;
            }
            if(Token=="NUM")
            {
                switch(flag)
                {
                    case 1:
                    {
                        char temp[20];
                        strcpy(temp,Lexeme.c_str());
                        char*stop;
                        int res=strtol(temp,&stop,8);
                        Lexeme=to_string(res);
                        newSymbol.lexeme=Lexeme;
                        break;
                    }
                    case 2:
                    {
                        char temp[20];
                        strcpy(temp,Lexeme.c_str());
                        char*stop;
                        int res=strtol(temp,&stop,16);
                        Lexeme=to_string(res);
                        newSymbol.lexeme=Lexeme;
                    }
                    
                }
            }
            SymbolList.push_back(newSymbol);
        }

        void CreateScope()
        {
            ScopeNode* new_node=new ScopeNode;
            new_node->father=ThisScope;
            ThisScope=new_node;
        }

        void EndScope()
        {
            if(ThisScope->father==0)
            {
                output<<"WRONG:RBRACE UNPAIRED"<<endl;
                return;
            }
            ThisScope=ThisScope->father;
        }

        void PrintMsg()
        {
            if(ThisScope->father!=0)
            {
                output<<"WRONG:LBRACE UNPAIRED"<<endl;
                return;
            }
            output<<endl;
            output<<setw(16)<<"token"<<setw(10)<<"lexeme"<<setw(8)<<"lineno"<<setw(20)<<"pointer_to_scope"<<endl;
            int size=SymbolList.size();
            for(int i=0;i<size;i++)
            {
                if(SymbolList[i].now_scope==0)
                    output<<setw(16)<<SymbolList[i].token<<setw(10)<<SymbolList[i].lexeme<<setw(8)<<SymbolList[i].lineno<<endl;
                else
                    output<<setw(16)<<SymbolList[i].token<<setw(10)<<SymbolList[i].lexeme<<setw(8)<<SymbolList[i].lineno<<setw(20)<<SymbolList[i].now_scope<<endl;
            }
        }
    };

    SymbolTable table;


    //#endif
%}



HEXADECIMAL (0x[1-9A-F][0-9A-F]*)
OCTAL (0[1-7][0-7]*)
DECIMIAL ([1-9][0-9]*|0)
ID [[:alpha:]_][[:alpha:][:digit:]_]*

BLOCKCOMMENTBEGIN "/*"
BLOCKCOMMENTELEMENT .|\n
BLOCKCOMMENTEND "*/"
%x BLOCKCOMMENT

LINECOMMENTBEGIN "//"
LINECOMMENTELEMENT .
LINECOMMENTEND \n
%x LINECOMMENT

EOL (\r\n|\n|\r)
WHITE [\t ]

%%

"int" {
    /*
    * Questions: 
    *   Q1: Why we need to return INT in further labs?
    *   Q2: What is "INT" actually?
    */
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("INT\tint");
        table.AddSymbol("INT","int",yylineno);
    #else
        return INT;
    #endif
}
"void" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("VOID\tvoid");
        table.AddSymbol("VOID","void",yylineno);
    #else
        return VOID;
    #endif 
}
"if" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("IF\tif");
        table.AddSymbol("IF","if",yylineno);
    #else
        return IF;
    #endif
};
"else" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("ELSE\telse");
        table.AddSymbol("ELSE","else",yylineno);
    #else
        return ELSE;
    #endif
}
"do" {
     #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("DO\tdo");
        table.AddSymbol("DO","do",yylineno);
    #else
        return DO;
    #endif
}
"while" {
     #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("WHILE\twhile");
        table.AddSymbol("WHILE","while",yylineno);
    #else
        return WHILE;
    #endif
}
"for" {
     #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("IF\tif");
        table.AddSymbol("IF","if",yylineno);
    #else
        return IF;
    #endif
}
"return" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("RETURN\treturn");
        table.AddSymbol("RETURN","return",yylineno);
    #else
        return RETURN;
    #endif
}
"==" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("EQUAL\t==");
        table.AddSymbol("EQUAL","==",yylineno);
    #else
        return EQUAL;
    #endif
}
"=" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("ASSIGN\t=");
        table.AddSymbol("ASSIGN","=",yylineno);
    #else
        return ASSIGN;
    #endif
}
"<=" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("LESSOREQUAL\t<=");
        table.AddSymbol("LESSOREQUAL","<=",yylineno);
    #else
        return LESSOREQUAL;
    #endif
}
"<" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("LESS\t<");
        table.AddSymbol("LESS","<",yylineno);
    #else
        return LESS;
    #endif
}
">=" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("GREATEROREQUAL\t>=");
        table.AddSymbol("GREATEROREQUAL",">=",yylineno);
    #else
        return GREATEROREQUAL;
    #endif
}
">" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("GREATER\t>");
        table.AddSymbol("GREATER",">",yylineno);
    #else
        return GREATER;
    #endif
}
"+" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("ADD\t+");
        table.AddSymbol("ADD","+",yylineno);
    #else
        return ADD;
    #endif
}
"-" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("SUB\t+");
        table.AddSymbol("SUB","-",yylineno);
    #else
        return SUB;
    #endif
}
"*" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("MUL\t+");
        table.AddSymbol("MUL","*",yylineno);
    #else
        return MUL;
    #endif
}
"/" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("DIV\t/");
        table.AddSymbol("DIV","/",yylineno);
    #else
        return DIV;
    #endif
}
";" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("SEMICOLON\t;");
        table.AddSymbol("SEMICOLON",";",yylineno);
    #else
        return SEMICOLON;
    #endif
}
"(" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("LPAREN\t(");
        table.AddSymbol("LPAREN","(",yylineno);
    #else
        return LPAREN;
    #endif
}
")" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("RPAREN\t)");
        table.AddSymbol("RPAREN",")",yylineno);
    #else
        return RPAREN;
    #endif
}
"{" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("LBRACE\t{");
        table.CreateScope();
        table.AddSymbol("LBRACE","{",yylineno);
    #else
        return LBRACE;
    #endif
}
"}" {
    #ifdef ONLY_FOR_LEX
        //DEBUG_FOR_LAB4("RBRACE\t}");
        table.EndScope();
        table.AddSymbol("RBRACE","}",yylineno);
    #else
        return RBRACE;
    #endif
}


{ID} {table.AddSymbol("ID",yytext,yylineno);}

{HEXADECIMAL} {table.AddSymbol("NUM",yytext,yylineno,2);}
{OCTAL} {table.AddSymbol("NUM",yytext,yylineno,1);}
{DECIMIAL} {table.AddSymbol("NUM",yytext,yylineno,0);}

{BLOCKCOMMENTBEGIN} {BEGIN BLOCKCOMMENT;}
<BLOCKCOMMENT>{BLOCKCOMMENTELEMENT} {}
<BLOCKCOMMENT>{BLOCKCOMMENTEND} {BEGIN INITIAL;}
{LINECOMMENTBEGIN} {BEGIN LINECOMMENT;}
<LINECOMMENT>{LINECOMMENTELEMENT} {}
<LINECOMMENT>{LINECOMMENTEND} {BEGIN INITIAL;}


{EOL} 
{WHITE}
%%

#ifdef ONLY_FOR_LEX
int main(){

    yyFlexLexer lexer(&input);
    lexer.yylex();
    table.PrintMsg();
    return 0;
}
#endif
