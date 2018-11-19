%{
#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<string> st;
string t1,t2;
string ans="";
%}

%%
[a-zA-Z0-9]+ { string s(yytext);st.push(s);}
[+|\-|*|/] {string op(yytext);ans="(";t1=st.top();st.pop();t2=st.top();st.pop();ans+=t2;ans+=op;ans+=t1;ans+=")";st.push(ans);}
. ;
%%

int main(){
	yylex();
	cout<<"Infix is "<<st.top()<<endl;
}

