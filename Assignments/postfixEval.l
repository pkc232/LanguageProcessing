%{
#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<int> st;
%}


%%
[0-9]+ {int x=atoi(yytext);st.push(x);}
[+] {int w1=st.top();st.pop();int w2=st.top();st.pop();st.push(w1+w2);}
[\-] {int w1=st.top();st.pop();int w2=st.top();st.pop();st.push(w2-w1);}
[*] {int w1=st.top();st.pop();int w2=st.top();st.pop();st.push(w1*w2);}
[/] {int w1=st.top();st.pop();int w2=st.top();st.pop();st.push(w2/w1);}

. ;
%%

int main(){
	yylex();
	cout<<st.top()<<endl;
}