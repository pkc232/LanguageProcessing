%{
#include <bits/stdc++.h>
using namespace std;
#include <cstdlib>
#include <string>
#include "y.tab.h"
%}

%option noyywrap

%%
[0-9]+(\.[0-9]+)?([eE][0-9]+)?	{yylval.f = atof(yytext);return NUM;}
"print"								{return print;}
[-+()/*]					 	{return yytext[0];}
[a-zA-Z_]+						{strcpy(yylval.str,yytext);return ID;}
[ \t\f ]						 {;}
%%