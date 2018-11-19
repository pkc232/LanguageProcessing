%{
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
string ans="";
%}


%%
"//"[a-zA-Z0-9. \t]+	{string s(yytext);std::transform(s.begin(), s.end(),s.begin(), ::toupper);ans+=s;}
"/*"[a-zA-Z0-9. \t\n]+"*/"  {string s(yytext);std::transform(s.begin(), s.end(),s.begin(), ::toupper);ans+=s;}
.						{string s(yytext);ans+=s;}

%%

int main(){
	// setKeywords();
	yylex();
	cout<<ans<<endl;
	return 0;
}
