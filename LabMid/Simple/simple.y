%{
#include <bits/stdc++.h>
using namespace std;
void yyerror(char *s);
map<string,int> table;
int yylex(void);
%}


%union{char id[100];int num;}
%start line
%token print if else then
%token exit_command


%token <num> number
%token <id>  ID

%type <num> exp term
%left '+'
%left '-'
%left '*'
%left '/'



%%
line			: assignment		';'		{;}
				| print exp			';'		{printf("Printing %d\n",$2);}
				| line exp			';'
				|line assignment	';'
				|line print exp		';'		{printf("Printing %d\n",$3);}
				|exit_command		';'		{exit(EXIT_SUCCESS);}
				|line exit_command	';'		{exit(EXIT_SUCCESS);}
				;
		 	


assignment		:ID '=' exp					{string s($1);table[s]=$3;}
				;



exp				:exp '+' exp			{$$=$1+$3;}
				|exp '-' exp			{$$=$1-$3;}
				|exp '*' exp			{$$=$1*$3;}
				|exp '/' exp			{$$=$1/$3;}
				|term					{$$=$1;}
				;	

term			:ID 					{string s($1);$$=table[s];}
				|number					{$$=$1;}	 
				;

%%

void yyerror(char *s){
	printf("Error = %s\n",s);
	return;
}


int main(void){
	return yyparse();
}