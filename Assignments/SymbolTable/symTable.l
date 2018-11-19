letter		[a-zA-Z]
digit		[0-9]

%{
	#include <bits/stdc++.h>
	using namespace std;

	void foundWord(char*);
	struct value {
		int freq;
		std::vector<int> lineNos;
	};
	std::map<string, value> table;
	std::map<string, int> lastInsertMap;
	int line = 1;
%}

%%
{letter}+'?{letter}*			{foundWord(yytext);}
\n 								{line++;}
%%

void foundWord(char* tmp) {
	string text(tmp);
	map<string, value>::iterator it = table.find(text);

	if (it != table.end()) {
		it->second.freq++;
		if (lastInsertMap.find(text) != lastInsertMap.end() 
			&& lastInsertMap[text] != line) {

			it->second.lineNos.push_back(line);
			lastInsertMap[text] = line;
		} 
	} 
	else {
		value v;
		v.freq = 1;
		v.lineNos.push_back(line);
		table[text] = v;
		lastInsertMap[text] = line;
	}
}

void printSymbolTable() {
	map<string, value>::iterator it = table.begin();
	printf("Word\t\tFrequency\t\tLine numbers\n");
	while (it != table.end()) {
		printf("%s\t", it->first.c_str());
		if (it->first.length() < 8)
			printf("\t");
		printf("%d\t\t\t", it->second.freq);
		for (int i = 0; i < it->second.lineNos.size(); i++) {
			printf("%d, ", it->second.lineNos[i]);
		}
		it++;
		printf("\n");
	}
}

int main() {
	yylex();
	printf("\n\n\n");
	cout<<"Scanning done!\n";
	printSymbolTable();
}