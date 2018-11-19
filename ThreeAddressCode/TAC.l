%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

char c;

%}

DIGIT  [0-9]+
ID [a-zA-Z_][0-9a-zA-Z_]*
FLOAT [0-9]+[.][0-9]*


ARITHMETIC_OPERATORS ['+' '\-' '*' '/' '^' '%' '@'',']
OTHER_CHARACTERS ['=' ';' '(' ')' '{' '}'':']
TYPES ["int" "float" "long" "char" "double"]

%%
[ \t] ;
[\n] ;


"if" 	{ return (IF); }
"else" 	{ return (ELSE); }
"while"	{ return (WHILE); }
"switch" { return (SWITCH);}
"case"	{return (CASE);}

"int"	{ return (TYPES); }
"float"	{ return (TYPES); }
"long"	{ return (TYPES); }
"char"	{ return (TYPES); }
"double"	{ return (TYPES); }
"default"	{return (DEFAULT);}
"for"		{return (FOR);}

"|"		{
		yylval.sval=strdup(yytext);
		return BOR;
		}
"&"		{
		yylval.sval=strdup(yytext);
		return BAND;
		}
"^"		{
		yylval.sval=strdup(yytext);
		return BXOR;
		}
"+="   {yylval.sval = strdup(yytext);
		return (PE);} 
"-="	{yylval.sval = strdup(yytext);
		return (ME);}
"*="	{yylval.sval = strdup(yytext);
		return (IE);}
"/="	{yylval.sval = strdup(yytext);
		return (DE);}
">"	{yylval.sval = strdup(yytext);
		return (REL_OPT);}
"<"	{yylval.sval = strdup(yytext);
		return (REL_OPT);}
">="	{yylval.sval = strdup(yytext);
		return (REL_OPT);}
"<="	{yylval.sval = strdup(yytext);
		return (REL_OPT);}
"!="	{yylval.sval = strdup(yytext);
		return (REL_OPT);}
"=="	{yylval.sval = strdup(yytext);
		return (REL_OPT);}

"||"	{yylval.sval = strdup(yytext);
		return (OR);}
"&&"	{yylval.sval = strdup(yytext);
		return (AND);}
"!"	{yylval.sval = strdup(yytext);
		return (NOT);}
"true"	{yylval.sval = strdup(yytext);
		return (TRUE);}
"false"	{yylval.sval = strdup(yytext);
		return (FALSE);}
"++"	{yylval.sval = strdup(yytext);
		return (INCR);}
"--"	{yylval.sval = strdup(yytext);
		return (DECR);}


{ID} {
	    yylval.sval = strdup(yytext);
	    return ID; }

{DIGIT}  { yylval.ival = atoi(yytext);
	   return DIGIT; }

{FLOAT}  { yylval.fval = atof(yytext);
	   return FLOAT; }


{ARITHMETIC_OPERATORS}   {
            	c = yytext[0];
                 return(c);
              }

{OTHER_CHARACTERS}   {
                 c = yytext[0];
                 return(c);
              }

%%