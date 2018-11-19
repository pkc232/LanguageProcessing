#include <bits/stdc++.h>
#define pb push_back
#define ITR map<char,vector<string> >::iterator
#define ITR2 map<string,vector<string> >::iterator
using namespace std;

map<char,vector<string> > M; 
map<string,vector<string> > newG;
char curr='A';


void removeLeftRecur(char c,string s){
	vector<string> v = M[c];
	for(int i=0;i<v.size();i++){
		if(v[i][0]==c)
			continue;
		else
		{
			string ns = "";
			ns+=v[i];
			ns+=curr;
			ns+='\'';
			string rs="";
			rs+=curr;
			newG[rs].pb(ns);
			rs+='\'';
			string rem=s.substr(1);
			rem+=rs;
			newG[rs].pb(rem);
			newG[rs].pb("eps");
			curr++;
		}
	}
}


void printProductions(){
	ITR2 it = newG.begin();
	set<string> done;
	while(it!=newG.end()){
		vector<string> v = it->second;
		done.clear();
		for(int i=0;i<v.size();i++)
			if(done.find(v[i])==done.end()){
			cout<<it->first<<" : "<<v[i]<<endl;
			done.insert(v[i]);
		}
		it++;
	}
}



int main(int argc, char const *argv[])
{
	
	cout<<"Enter the rules 0 to exit\n";
	char left;string right;
	while(1){
		cin>>left;
		if(left=='0')
			break;
		cin>>right;
		M[left].pb(right);
	}

	ITR it;

	it = M.begin();

	while(it!=M.end()){
		vector<string> v = it->second;

		for(int i=0;i<v.size();i++){
			if(v[i][0]==it->first){
				removeLeftRecur(it->first,v[i]);
			}

		}
		it++;

	}
	printProductions();

	return 0;
}