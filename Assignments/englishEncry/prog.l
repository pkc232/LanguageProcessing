letter		[a-zA-Z]
digit		[0-9]
%{
	#include <bits/stdc++.h>
	#include <stdlib.h>
	using namespace std;

	bool isSpecial(string );
	string leftRotate(string );
	string rightRotate(string );
	void foundWord(char* , int );
	void foundNumber(char*);
	void foundGen(char*);

	vector<string> spclWords;
%}
%%
{letter}+'?{letter}*			{foundWord(yytext, yyleng);}
{digit}+						{foundNumber(yytext);}
.								{foundGen(yytext);}
%%

bool isSpecial(string word) {
	if (find(spclWords.begin(), spclWords.end(), word) != spclWords.end())
		return true;
	return false;
}

string leftRotate(string tmp) {
	if (tmp.length() <= 2)
		return tmp;
	int l = tmp.length();
	char charAt0 = tmp[0], charAt1 = tmp[1];
	for (int i = 2; i < l; i++) 
		tmp[i - 2] = tmp[i];

	tmp[l - 2] = charAt0;
	tmp[l - 1] = charAt1;
	
	reverse(tmp.begin(), tmp.end());
	return tmp;

}

string rightRotate(string tmp) {
	if (tmp.length() <= 2)
		return tmp;
	int l = tmp.length();
	char charAtn = tmp[l-1], charAtn_1 = tmp[l-2];
	for (int i = l-1; i >= 0; i--) 
		tmp[i] = tmp[i - 2];

	tmp[1] = charAtn;
	tmp[0] = charAtn_1;
	
	reverse(tmp.begin(), tmp.end());
	return tmp;
}


void foundWord(char* text, int len) {
	string txt(text);
	string cat = "";
	if (isSpecial(txt)) {
		txt = leftRotate(txt);
		cat = " is special ";
	} else {
		txt = rightRotate(txt);
		cat = "is not special ";
	}
	printf("%s", txt.c_str());
}

void foundNumber(char* text) {
	string txt(text);
	int len = txt.length();
	int mid = len/2;
	string firstHalf = txt.substr(0, mid);
	string secHalf = txt.substr(mid, len);
	secHalf += firstHalf;
	printf("%s", secHalf.c_str());
}

void foundGen(char* text) {
	printf("%s", text);
}

void buildSpecialVector() {
	ifstream fin;
	fin.open("special.txt");
	while (true) {
		stringstream ss;
		string buf;
		getline(fin, buf);
		ss<<buf;
		string tmp;
		while (ss>>tmp) {
			spclWords.push_back(tmp);
		}

		if (fin.eof())
			break;
	} 
}

int main() {
	buildSpecialVector();
	yylex();
}