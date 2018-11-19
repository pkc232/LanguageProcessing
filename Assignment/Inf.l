%{
#include <bits/stdc++.h>
#include "y.tab.h"
using namespace std;
void yyerror(char* s);
%}
%%

"print" 	{return print;}
"exit"		{return exit_command;}
[a-zA-Z]+	{strcpy(yylval.id,yytext); return identifier;}
[0-9]+		{yylval.num=atoi(yytext); return number;}
[ \t\n]+	{;}

"--"		{return minusminus;}
"@"			{return power;}
"+="		{return PE;}
"-="		{return ME;}
"*="		{return SE;}
"/="		{return DE;}		
"|"			{return OR;}
"&"			{return AND;}
"^"			{return XOR;}
"~"			{return yytext[0];}
[-|+|\|*|=|;]		{return yytext[0];}
"++"		{return plusplus;}
"("				{return bracketOpen;}
")"			{return bracketClose;}

.			{ECHO; yyerror("Unexpected character");}

%%

int yywrap(void) {return 1;}
