%{
#include <bits/stdc++.h>
using namespace std;
map <char,int> table;
void yyerror(char*s);
int yylex(void);
%}


%union {int num; char id;}
%start line
%token print
%token exit_command
%token bracketopen
%token bracketclose
%token <num> number
%token <id> identifier
%type <num> line exp term factor
%type <id> assignment




%%

line	: assignment ';'		{;}
		| exit_command ';'		{exit(EXIT_SUCCESS);}
		| print exp ';'			{printf("Printing %d\n",$2);}
		| line assignment ';'	{;}
		| line print exp   ';'	{printf("Printing %d\n",$3);}
		| line exit_command ';'	{exit(EXIT_SUCCESS);}
		;

assignment : identifier '=' exp {table[$1]=$3;}

exp		: term 					{$$=$1;}
		| exp '+' term 			{$$=$1+$3;}
		| exp '-' term 			{$$=$1-$3;}
		;


term	: 	factor				{$$=$1;}
		|	term '*' factor		{$$=$1*$3;}
		|	term '/' factor 	{$$=$1/$3;}
		;
factor 	:	bracketopen exp bracketclose			{$$=$2;}
	 	| number 				{$$=$1;}
		| identifier			{if(table.find($1)!=table.end())$$=table[$1];else printf("%c not defined\n",$1);}
		;

%%

void yyerror(char *s){
	printf("the error \n");
	return;
}

int main(void){
	return yyparse();
}