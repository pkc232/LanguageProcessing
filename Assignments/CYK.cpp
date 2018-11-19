#include <bits/stdc++.h>
#define pb push_back
using namespace std;


map <char,vector<string> >productions;
map <string,vector<char> >converse;

vector<vector<set<char> > > table;

int n;

void storeProductions(){
	cout<<"Enter the number of production rules\n";
	cin>>n;
	
	cout<<"Enter the rules\n";
	
	char left;
	string right;
	
	
	for(int i=0;i<n;i++){
		cin>>left;
		cin>>right;
		productions[left].pb(right);
		converse[right].pb(left);
	}
}

bool initiate(string s){
	int l=s.length();
	
	vector<set<char> > lowest;
	
	string temp="";
	set<char> stmp;
	char source;

	for(int i=0;i<l;i++){
		temp="";
		temp+=s[i];
		stmp.clear();
		if(converse.find(temp)==converse.end())
			return false;
		for(int w=0;w<converse[temp].size();w++){
		source=converse[temp][w];
		stmp.insert(source);	
		}
		lowest.pb(stmp);
	}
	table.pb(lowest);	
	return true;
}

void insertUnion(set<char> &left,set<char> &right,set<char> &curr){
	
	set<char> :: iterator it1,it2;
	
	it1=left.begin();
	
	char c1,c2,src;
	string temp;
	
	while(it1!=left.end()){
		it2=right.begin();
		while(it2!=right.end()){
		c1=(*it1);
		c2=(*it2);
		temp="";
		temp+=c1;
		temp+=c2;
		char source;
		if(converse.find(temp)!=converse.end()){
			for(int w=0;w<converse.size();w++){
			source=converse[temp][w];
			curr.insert(source);	
			}
		}
		it2++;	
		}
		it1++;
	}
	
}

void printSet(set<char> st){
	set<char> ::iterator it;
	it=st.begin();
	
	while(it!=st.end()){
		cout<<(*it)<<" ";
		it++;
	}
	cout<<endl;
}

void generate(){
	int sz=table.size();
	// cout<<sz<<endl;
	set<char> left;
	set<char> right;
	int lr,lc,rr,rc;
	
	vector<set<char> > newRow;
	
	for(int i=0;i<table[sz-1].size()-1;i++){
		lr=0;
		lc=i;
		
		rr=sz-1;
		rc=i+1;
		set<char> currset;
		currset.clear();
		while(lr<sz){
			left=table[lr][lc];
			right=table[rr][rc];
			
			// printSet(left);
			// printSet(right);
			
			
			insertUnion(left,right,currset);
			
			lr++;
			rr--;
			rc++;
		
			
		}
			newRow.pb(currset);
	}
	// cout<<"New row being inserted\n";
	// for(int i=0;i<newRow.size();i++){
		// printSet(newRow[i]);
	// }
	
	
	table.pb(newRow);
}

bool CYK(string s){
	if(!initiate(s))
		return false;
	int l=s.length();
	for(int i=0;i<l-1;i++){
		generate();
	}
	
	return (table[table.size()-1][0].find('S')!=table[table.size()-1][0].end());
	
	
}


int main(){
	cout<<(~4)<<endl;
	storeProductions();
	cout<<"Enter the string whose membership you want\n";
	
	string input;
	cin>>input;
	
	if(CYK(input))
	cout<<"It is a member\n";
	else
	cout<<"It is not a member\n";
		
	
}
