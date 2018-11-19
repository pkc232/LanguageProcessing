%{
	#include <bits/stdc++.h>
	using namespace std;


	map<string,string> symbolTable;
	string ans="";
	string classify(char *arr);
	set<string> keyword;
	bool isNum(char x);

%}


%%
[a-zA-Z0-9.]+  		{ans+=classify(yytext);ans+=" ";}
[+-/*><]+			{ans+=" operator ";}
"=="|"="		{ans+=" operator ";}

.					{ans+=yytext;}
%%

bool isNum(char x){
	return (x>='0'&&x<='9');

}

void setKeywords(){
	keyword.insert("if");
	keyword.insert("break");
	keyword.insert("else");
	keyword.insert("for");
	keyword.insert("while");
	keyword.insert("int");
	keyword.insert("float");
	keyword.insert("char");
	keyword.insert("double");
	keyword.insert("cout");
	keyword.insert("cin>>");
	
}


string classify(char *arr){
	string temp(arr);
	cout<<temp<<endl;
	if(keyword.find(temp)!=keyword.end())
		return "keyword";
	else if(isNum(temp[0]))
		return "num";
	else
		return "id";
}

int main(){
	setKeywords();
	yylex();
	cout<<ans<<endl;
	return 0;
}
