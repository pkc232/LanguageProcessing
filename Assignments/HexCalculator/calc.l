%{
	#include <bits/stdc++.h> 
	using namespace std;
	
	float num;
	stack<char> opertor;		//stack to store the operators
	stack<float> operand;		//stack to store the operands
	map<char,int> prec;			//for storing the precedence rules
	map<int,char> correspondingChar;	


	float emptyStack();			
	void setOperands();
	bool checkInt(float num);
	float operate(float n1,float n2,char op);
	void checkForPrec(char op);
	float convertToDecimal(string s);
	union ulf{
		unsigned long ul;
		float f;
	};
	
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

//function to convert a hexadecimal number to decimal
float convertToDecimal(string s){
	ulf u;
	stringstream ss;
	float x;
	ss<<s;
	ss>>hex>>u.ul;
	x= u.f;
	return x;
}

//function to check if the number passed is an integer or floating point
bool checkInt(float num){
	return (ceil(num)==floor(num));
}

//perform operation on the numbers
float operate(float n1,float n2,char op){
	if(op=='+')
	return n1+n2;
	if(op=='-')
	return n1-n2;
	if(op=='/')
	return n1/n2;
	if(op=='*')
	return n1*n2;
	int num1,num2;
	if(checkInt(n1)&&checkInt(n2))
	{
		num1=(int)n1;
		num2=(int)n2;
	}
	else
	{
		cout<<"Please enter integers for bitwise operation\n";
		return 0;
	}
	if(op=='|')
	return num1|num2;
	if(op=='&')
	return num1&num2;
	if(op=='^')
	return num1^num2;
	if(op=='%')
	return num1%num2;
}

//set the precedence of the operands
void setOperands(){
	prec['|']=prec['&']=prec['^']=0;
	prec['+']=prec['-']=1;
	prec['*']=prec['/']=#|  |#prec['%']=2;
}


//check the stack for precedence of operators
void checkForPrec(char op){
	
	while(!opertor.empty()){
		char tp = opertor.top();
		if(prec[op]<=prec[tp]){
			float n1 = operand.top();operand.pop();
			float n2 = operand.top();operand.pop();
			float n = operate(n2,n1,tp);
			operand.push(n);
			opertor.pop();
		}
		else
		break;
	}
}

//perfrom operations on stack to empty it out
float emptyStack(){
	float ans=0;
	while(operand.size()>1){
		float n1 = operand.top();operand.pop();
		float n2 = operand.top();operand.pop();
		char op = opertor.top();opertor.pop();
		operand.push(operate(n2,n1,op));
	}
	return operand.top();
}
//convert decimal to hexadecimal
string decTohex(float num){
	std::stringstream stream;
	stream << std::hex << num;
	std::string result( stream.str() );
	return result;
}

int main(){
	setOperands();
	yylex();
	float ans =emptyStack();
	cout<<ans<<endl; 
	std::cout <<showbase<< std::hex <<ans<<endl; 
	printf("hex is  0x%x\n", *(unsigned int*)&ans);
	return 0;
}

