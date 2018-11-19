#include <bits/stdc++.h>
#define pb push_back
#define ITR1 map<char,vector<string> >::iterator
#define ITR2 map<string,vector<string> >::iterator
#define ITR3 map<char,set<char> >::iterator
#define ITR4 set<char> :: iterator
using namespace std;

map<char,vector<string> > Productions;
map<char,set<char> > First;
map<char,set<char> > Follow;
map<char,int> computed;

bool isTerminal(char x){
	return (x>='a'&&x<='z');
}

bool containsEps(set<char> &s){
	return (s.find('@')!=s.end());
}


void computeFirst(char X){

	if(First.find(X)!=First.end())
		return;

	if(isTerminal(X))
	{
		if(X=='@')
			return;
		First[X].insert(X);
		return;
	}
	// set<char> firstSymb;

	vector<string> v = Productions[X];

	for(int i=0;i<v.size();i++){
		string prod = v[i];
		int j;
		for(j=0;j<prod.length();j++){
			char fnd=v[i][j];

			if(fnd=='@')
			{
				First[X].insert('@');
				return;
			}
			// cout<<fnd<<endl;
			computeFirst(fnd);
			First[X].insert(First[fnd].begin(), First[fnd].end());
			if(!containsEps(First[fnd]))
				break;
		}
		if(j==prod.length())
			First[X].insert('@');

	}
}

void printSet(set<char> &S){
	ITR4 it = S.begin();

	while(it!=S.end()){
		cout<<(*it)<<" ";
		it++;
	}
}


void computeFollow(){
	ITR1 it = Productions.begin();

	while(it!=Productions.end()){
		vector<string> v = it->second;

		for(int i=0;i<v.size();i++){
			string s= v[i];

			for(int j=0;j<s.length();j++){
				if(s[j]=='@')
					break;
				if(!isTerminal(s[j])){
					//if(j==(s.length()-1))
					//	Follow[s[j]].insert(Follow[it->first].begin(),Follow[it->first].end());
					//else
					{
						//if(!containsEps(First[s[j]]))
						{
						Follow[s[j]].insert(First[s[j+1]].begin(),First[s[j+1]].end());
						}
					}
				}
			}
		}
		it++;
	}
}


void printSetMap(map<char,set<char> > &m){
	ITR3 it = m.begin();

	while(it!=m.end()){
		if(isTerminal(it->first))
		{
			break;
		}
		cout<<it->first<<"==>> ";
		printSet(it->second);
		cout<<endl;
		it++;
	}
}

void inputProductions(){
	cout<<"Enter the rules 0 to exit\n";
	char left;string right;
	while(1){
		cin>>left;
		if(left=='0')
			break;
		cin>>right;

		for(int i=0;i<right.size();i++){
			if(isTerminal(right[i]))
				First[right[i]].insert(right[i]);
		}
		Productions[left].pb(right);
	}
}




int main(int argc, char const *argv[])
{
	inputProductions();
	ITR1 it = Productions.begin();

	while(it!=Productions.end()){
		computeFirst(it->first);
		it++;
	}

	cout<<"The first are \n";

	printSetMap(First);

	computeFollow();

	Follow['A'].insert('$');

	cout<<"The follow are\n";

	printSetMap(Follow);

	return 0;
}