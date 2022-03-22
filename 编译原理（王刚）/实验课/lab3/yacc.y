%{
#include<stdio.h>
#include<stdlib.h>
#ifndef YYSTYPE
#define YYSTYPE double
#endif
int yylex();
extern int yyparse();
FILE* yyin;
void yyerror(const char* s);
%}

%token NUM
%token ADD
%token SUB
%token MUL
%token DEV
%token LB
%token RB

%left ADD SUB
%left MUL DEV
%right UMINUS

%%

lines	:	lines expr ';' { printf("%f\n", $2);}
	|	lines ';'
	|
	;

 expr	: 	expr ADD expr { $$ = $1 + $3; }
	| 	expr SUB expr { $$ = $1 - $3; }
	|	expr MUL expr { $$ = $1 * $3; }
	|	expr DEV expr { $$ = $1 / $3; }
	|	LB expr RB { $$ = $2; }
	|	'-' expr %prec UMINUS { $$ = -$2; }
	|	NUM
	;


%%

// programs section
int isdigit(int t){
	if(t=='0'||t=='1'||t=='2'||t=='3'||t=='4'||t=='5'||t=='6'||t=='7'||t=='8'||t=='9')return 1;
	else return 0;
}

int yylex()
{
	int temp;
	while(1){
		temp = getchar();
		if(temp==' '||temp=='\t'||temp=='\n'){
			//nothing to do
		}
		else{
		if(isdigit(temp)==1){
			yylval=0;
			while(isdigit(temp)==1){
				yylval=yylval*10+temp-'0';
				temp=getchar();
			}
			ungetc(temp, stdin);
			return NUM;
		}
		if(temp=='+')return ADD;
		if(temp=='-')return SUB;
		if(temp=='*')return MUL;
		if(temp=='/')return DEV;
		if(temp=='(')return LB;
		if(temp==')')return RB;
		return temp;
		}
	}
}

int main()
{
	yyin = stdin;
	do{
		yyparse();
	}while(!feof(yyin));
	return 0;
}

void yyerror(const char* s){
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
