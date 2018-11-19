%{
#include <bits/stdc++.h>
using namespace std;
extern int yylex();
void yyerror(char *msg);	
int valOf(char *s);
map<string,int> table;
%}

%union{
	float f;
	char str[100];
}

%token print
%token <f> NUM
%token <str> ID
%type <f> E
%type <f> T
%type <f> F





%%




S :	print E		{printf("%f\n",$2);}
  | assignment
  | S assignment
  ;

assignment : ID '=' E 	{table[string($1)]=$3;}

E : E '+' T 	{$$ = $1 + $3;}
  | E '-' T 	{$$ = $1 - $3;}
  | T 			{$$ = $1;}
  ;

T : T '*' F 	{$$ = $1 * $3;}
  | T '/' F 	{$$ = $1/$3;}
  | F 			{$$ = $1;}
  ;

F : '(' E ')'	{$$ = $2;}
  | '-' F 		{$$ = -$2;}
  | NUM			{$$ = $1;}
  | ID 			{$$ = valOf($1);}
  ;


 %%


void yyerror(char *msg){
	fprintf(stderr,"%s\n",msg);
	exit(1);
}

int valOf(char *s){
	string ss(s);
	if(table.find(ss)==table.end())
		yyerror("Wrong variable");
	else
		return table[ss];
}

int main(){
	yyparse();
	return 0;
}

