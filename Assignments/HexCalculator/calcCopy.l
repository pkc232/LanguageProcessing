%{
	#include <iostream>
	#include <string>
	#include <map>
	#include <stack>
	#include <algorithm>
	#include <sstream>
	using namespace std;
	
	int num;
	stack<char> opertor;
	stack<int> operand;
	map<char,int> prec;
	map<char,int> correspondingDigit;
	map<int,char> correspondingChar;


	int emptyStack();
	void setOperands();
	int operate(int n1,int n2,char op);
	void checkForPrec(char op);
	int convertToDecimal(string s);
	
%}

%%
[a-zA-Z0-9.]+ {string s(yytext);num=convertToDecimal(s);operand.push(num);}
[+] {checkForPrec('+');opertor.push('+');}
[\-] {checkForPrec('-');opertor.push('-');}
[*] {checkForPrec('*');opertor.push('*');}
[/]	{checkForPrec('/');opertor.push('/');}
[|] {checkForPrec('|');opertor.push('|');}
[&] {checkForPrec('&');opertor.push('&');}
[\^]	{checkForPrec('^');opertor.push('^');}
[%] {checkForPrec('%');opertor.push('%');}
. ;
%%

int convertToDecimal(string s){


	stringstream ss;
	int x;
	ss<<std::hex<<s;
	ss>>x;
	return x;

	int l = s.length();
	int ans=0;
	for(int i=0;i<10;i++){
		correspondingDigit[(char)('0'+i)]=i;
	}
	for(int i=0;i<6;i++){
		correspondingDigit[(char)('A'+i)]=correspondingDigit[(char)('a'+i)]=(10+i);
	}
	
	int i=0;
	while(i<l){
		ans*=16;
		ans+=correspondingDigit[s[i]];
		i++;
	}
	cout<<ans<<endl;
	return ans;
}

int operate(int n1,int n2,char op){
	if(op=='+')
	return n1+n2;
	if(op=='-')
	return n1-n2;
	if(op=='/')
	return n1/n2;
	if(op=='*')
	return n1*n2;
	if(op=='|')
	return n1|n2;
	if(op=='&')
	return n1&n2;
	if(op=='^')
	return n1^n2;
	if(op=='%')
	return n1%n2;
}

void setOperands(){
	prec['|']=prec['&']=prec['^']=0;
	prec['+']=prec['-']=1;
	prec['*']=prec['/']=prec['%']=2;
}

void checkForPrec(char op){
	
	while(!opertor.empty()){
		char tp = opertor.top();
		if(prec[op]<=prec[tp]){
			int n1 = operand.top();operand.pop();
			int n2 = operand.top();operand.pop();
			int n = operate(n2,n1,tp);
			operand.push(n);
			opertor.pop();
		}
		else
		break;
	}
}

int emptyStack(){
	int ans=0;
	while(operand.size()>1){
		int n1 = operand.top();operand.pop();
		int n2 = operand.top();operand.pop();
		char op = opertor.top();opertor.pop();
		operand.push(operate(n2,n1,op));
	}
	return operand.top();
}

string decTohex(int num){
	for(int i=0;i<10;i++)
		correspondingChar[i]=(char)('0'+i);
	for(int i=0;i<6;i++)
		correspondingChar[i+10]=(char)('A'+i);
	string ans="";
	while(1){
		int rem = num%16;
		num/=16;
		ans+=correspondingChar[rem];
		if(!num)
		break;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	setOperands();
	yylex();
	int ans =emptyStack(); 
	cout<<ans<<endl;
	cout<<decTohex(ans)<<endl;
	return 0;
}

