%{
	#include <stdio.h>
	#include <string.h>
	int convertToDecimal(string s);
	int num;
%}

%%
[a-zA-Z0-9]+ {string s(yytext);num=conver }
. ;
%%



