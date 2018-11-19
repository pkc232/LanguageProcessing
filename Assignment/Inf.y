%{
#include <bits/stdc++.h>
using namespace std;
map<string,int> val;
void yyerror(char* s);
int yylex(void);
%}

%union {int num; char id[100];}
%start line
%token print
%token bracketOpen
%token bracketClose
%left '*'
%left '/'
%left '+'
%left '-'


%token exit_command plusplus minusminus power PE ME SE DE
%token AND OR XOR
%token <num> number
%token <id> identifier
%type <num> line exp term factor g
%type <id> assignment
%type <num> exp1


%%

line	: assignment ';'	  {;}	
		| factor	';'		  {;}
		| exit_command ';'	  {exit(EXIT_SUCCESS);}
		| print exp ';' 	  {printf("Printing %d \n",$2);}
		| line assignment ';' {;}
		| line print exp ';'  {printf("Printing %d \n",$3);}
		| line exit_command ';'{exit(EXIT_SUCCESS);}
		;
assignment	: identifier '=' exp1 {string s($1) ;val[s]=$3;}
			| identifier PE exp1	{string s($1); val[s]+=$3;}
			| identifier ME exp1	{string s($1); val[s]-=$3;}
			| identifier SE exp1	{string s($1); val[s]*=$3;}
			| identifier DE exp1	{string s($1); val[s]/=$3;}
			;	

exp1		: exp 					{$$ = $1;}
			| exp1 AND exp 			{$$ = $1&$3;}
			| exp1 OR exp 			{$$ =$1|$3;}
			| exp1 XOR exp 			{$$=$1^$3;}
			; 


exp	:	term	{$$=$1;}
	| 	exp '+' term {$$=$1+$3;}
	|	exp '-'	term {$$=$1-$3;}
	;
term	:	term '*' g	{$$=$1*$3;}
		|   term '/' g {$$=$1/$3;}
		|   g		{$$=$1;}
		;

g		:   factor power g		{$$ = (int)pow($1,$3);}
		|	factor		
		;
factor 	:	bracketOpen exp bracketClose			{$$ = $2;}	
		|   '-' number								{$$ = -$2;}
		|   '-' identifier							{string s($2);$$ = -val[s];}
		| 	'~' number								{$$=~$2;}
		| 	'~' identifier 							{string s($2);$$ = ~val[s];}
		| 	number									{$$=$1;}
		| 	identifier      						{string s($1);$$=val[s];}	
		|   identifier plusplus						{string s($1);$$ = val[s];val[s]++;}
		|   identifier minusminus 					{string s($1);$$ = val[s];val[s]--;}
		;
%%

void yyerror(char* s){
	printf("Error = %s\n", s);
	return;
}

int main(void)
{
	return yyparse();
}				 				