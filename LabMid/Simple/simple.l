%{
#include <bits/stdc++.h>
using namespace std;
#include "y.tab.h"
void yyerror(char *s);
%}



%%


"print" 						{return print;}
"exit"							{return exit_command;}
"if"							{return if;}
"else"							{return else;}
"then"							{return then;}
[a-zA-Z]+						{strcpy(yylval.id,yytext);return ID;}
[0-9]+							{yylval.num=atoi(yytext);return number;}
[+|-|*|/|;|=]						{return yytext[0];}
[ \t\n]+						{;}


%%


int yywrap(void){
	return 1;
}