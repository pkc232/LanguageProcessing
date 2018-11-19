#include <bits/stdc++.h>
#define pb push_back
#define ITR map<char,vector<string> >::iterator
#define ITR2 map<string,vector<string> >::iterator
using namespace std;

map<char,vector<string> > M; 
map<string,vector<string> > newG;
char curr='A';

string findLongest(vector<string> &v){
	int mlind=0;
	int ml=v[0].length();
	for(int i=1;i<v.size();i++){
		if(v[i].length()<ml){
			ml=v[i].length();
			mlind=i;
		}
	}
	string pref="";
	// v.erase(v.begin()+mlind);
	for(int i=0;i<v[mlind].size();i++){
		for(int j=0;j<v.size();j++){
			if(v[j][i]!=v[mlind][i]){
				return pref;
			}
		}
		pref+=v[mlind][i];
	}
	return pref;
}

vector<string> removePrefix(vector<string> &v,int l){
	string temp="";
	vector<string> ans;
	for(int i=0;i<v.size();i++){
		temp="";
		for(int j=l;j<v[i].length();j++)
			temp+=v[i][j];
		ans.pb(temp);
	}
	return ans;
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

	it=M.begin();
	char curr='T';
	while(it!=M.end()){
		vector<string> v= it->second;
		char rule = it->first;
		string longestPrefix = findLongest(v);
		cout<<"Longest Prefix is : "<<longestPrefix<<endl;
		if(longestPrefix.length()>0&&v.size()>1){
		string temp="";
		temp+=longestPrefix;
		temp+=(char)(curr);
		

		temp+='\'';
		string s1="";
		s1+=rule;

		string s2="";
		s2+=curr;
		s2+='\'';
		newG[s1].pb(temp);
		newG[s2]=removePrefix(v,longestPrefix.length());
		curr++;
		}

		else
		{
			string s1="";
			s1+=rule;
			newG[s1]=v;
		}
		it++;
	}

	printProductions();
	return 0;
}