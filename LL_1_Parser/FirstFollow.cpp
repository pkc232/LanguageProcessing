#include <bits/stdc++.h>
#include <unistd.h>
#define ITR1 map<string,vector<string> >::iterator 
#define ITR2 map<char,triePtr>::iterator 
#define ITR3 map<string,set<string> > :: iterator
#define ITR4 set<string> :: iterator
#define prodn map<string,vector<string> >
#define triePtr trieNode*
#define pb push_back
#define mp make_pair
using namespace std;

string eps = "\u03B5";
void computeFollow(string var);
void printStack(stack<string> s);

prodn Prod;
map<string,set<string>  >First;
map<string,set<string>  >Follow;
set<string> terminals;
set<string> nonTerminals;
map<pair<string,string>,string> Table; 

void computeFirst(string var);

bool isTerminal(string x){
	return ((!(x[0]>='A'&&x[0]<='Z'))||x==eps);
}

string minusPrefix(string s1,string s2){
	int l = s2.size();

	return s1.substr(l);
}

int beginSame(string &s1,string &s2){
	int l =s2.length();
	int i=0;
	while(i<l){
		if(s1[i]!=s2[i])
			return 0;
		i++;
	}

	return 1;
}



string toStr(char x){
	string s="";
	s+=x;
	return s;
}

void addFirst(string S,string left){

	if(S==eps)
	{
		First[left].insert(eps);
		return;
	}
	for(int i=0;i<S.length();i++){
		string temp = toStr(S[i]);
		if(isTerminal(temp))
		{
			First[left].insert(temp);
			return;
		}
		else
		{
			computeFirst(temp);
			ITR4 it = First[temp].begin();
			int fl = 0;
			while(it!=First[temp].end()){
				if((*it)==eps)
					fl=1;
				else
					First[left].insert((*it));
				it++;
			}
			if(fl==0)
				return;
		}
	}
	First[left].insert(eps);
}


void computeFirst(string var){

	if(First.find(var)!=First.end())
		return;

	if(isTerminal(var)){
		First[var].insert(var);
		return;
	}
	else
	{
		vector<string> ryt = Prod[var];

		for(int i=0;i<ryt.size();i++){
			string Y = ryt[i];
			addFirst(Y,var);
		}
	}
}

void addTerminals(string s){

	if(s==eps){
		First[eps].insert(eps);
		return;
	}

	for(int i=0;i<s.length();i++){
		if(isTerminal(toStr(s[i])))
		{
			terminals.insert(toStr(s[i]));
			First[toStr(s[i])].insert(toStr(s[i]));
		}
	}
}

void inputProductions(){
	terminals.insert("$");
	string left,right;
	cout<<"Enter the rules 0 to exit\n";
	while(1){
		cin>>left;
		nonTerminals.insert(left);
		if(left=="0")
			break;
		cin>>right;
		addTerminals(right);
		Prod[left].pb(right);
	}
}

void printProductions(prodn &prods){
	ITR1 it = prods.begin();
	set<string> done;
	while(it!=prods.end()){
		vector<string> v = it->second;
		done.clear();
		cout<<it->first<<"==> ";
		for(int i=0;i<v.size();i++)
			if(done.find(v[i])==done.end()){
			if(!beginSame(v[i],eps)||v[i]==eps)
			cout<<v[i]<<" |  ";
			else{
				cout<<minusPrefix(v[i],eps)<<" |  ";
			}
			done.insert(v[i]);
		}
		cout<<endl;
		it++;
	}
}

void printSet(set<string> &S){
	ITR4 it = S.begin();

	while(it!=S.end()){
		cout<<(*it)<<" ";
		it++;
	}
}


void computeFirstWrapper(){
	ITR1 it = Prod.begin();

	while(it!=Prod.end()){
		computeFirst(it->first);
		it++;
	}
}

void printSetMap(map<string,set<string> > &m){
	ITR3 it = m.begin();

	while(it!=m.end()){
		 if(it->first==eps||isTerminal(it->first))
		{
			it++;
			continue;
		}
		cout<<it->first<<"==>> ";
		printSet(it->second);
		cout<<endl;
		it++;
	}
}

set<string> getFirst(string s){
	set<string> ans;
	for(int i=0;i<s.length();i++){
		set<string> st = First[toStr(s[i])];
		ITR4 it = st.begin();
		int fl=0;
		while(it!=st.end()){
			if((*it)==eps)
				fl=1;
			else
				ans.insert((*it));
			it++;
		}
		if(fl==0)
			return ans;
	}
	ans.insert(eps);
	return ans;
}

void addFollow(string s1,string s2,ITR1 it){
	if(s1==eps)
		return ;
	int i;
	for(i=0;i<(int)s1.length()-1;i++){
		if(toStr(s1[i])==s2){
			string str = s1.substr(i+1);
			set<string> ans=getFirst(str);

			ITR4 it2 = ans.begin();
			int fl=0;
			while(it2!=ans.end()){
				if((*it2)==eps)
					fl=1;
				else
					Follow[s2].insert((*it2));
				it2++;
			}
			if(fl){
				if(it->first!=toStr(s1[i])){
				computeFollow(it->first);
				Follow[s2].insert(Follow[it->first].begin(),Follow[it->first].end());
				}
			}
		}
	}

	if(toStr(s1[i])==s2){
		if(it->first!=toStr(s1[i])){
			computeFollow(it->first);
			Follow[s2].insert(Follow[it->first].begin(),Follow[it->first].end());
		}
	}
}

void computeFollow(string var){

	// if(Follow.find(var)!=Follow.end())
		// return;
	ITR1 it = Prod.begin();

	while(it!=Prod.end()){
		vector<string> ryt= it->second;
		for(int i=0;i<ryt.size();i++){
				addFollow(ryt[i],var,it);
		}
		it++;
	}
}

void computeFollowWrapper(){

	Follow[toStr('S')].insert("$");
	ITR1 it = Prod.begin();

	while(it!=Prod.end()){
		// cout<<it->first<<endl;
		computeFollow(it->first);
		it++;
	}
}

void constructTable(){
	ITR1 it = Prod.begin();
	while(it!=Prod.end()){
		vector<string> v= it->second;

		for(int i=0;i<v.size();i++){
			
			if(v[i]==eps){
				set<string> nst = Follow[it->first];
				ITR4 it3 = nst.begin();
				while(it3!=nst.end()){
					cout<<it->first<<" "<<(*it3)<<"\t"<<eps<<endl;
					Table[mp(it->first,(*it3))]=v[i];
					it3++;
				}
				continue;
			}

		set<string> st = getFirst(v[i]);
		ITR4 it2 = st.begin();
		while(it2!=st.end()){
			if((*it2)!=eps){
				Table[mp(it->first,(*it2))]=v[i];
				cout<<it->first<<" "<<(*it2)<<"\t";
				cout<<Table[mp(it->first,(*it2))]<<endl;
			}
			else
			{
				cout<<"idhr\n";
				set<string> nst = Follow[it->first];
				ITR4 it3 = nst.begin();
				while(it3!=nst.end()){
					cout<<it->first<<" "<<(*it3)<<"\t";
					Table[mp(it->first,(*it3))]=v[i];
					it3++;
				}
			}
			it2++;
		}	
		}
		
		it++;
	}
}

void printTable(){
	ITR4 it1,it2;
		it2= terminals.begin();
		cout<<"\t";
		while(it2!=terminals.end()){
			cout<<(*it2)<<"\t";
			it2++;
		}


	it1=nonTerminals.begin();


	while(it1!=nonTerminals.end()){
		it2 = terminals.begin();
		while(it2!=terminals.end()){
		 cout<<(*it1)<<"\t";
		if(Table.find(mp((*it1),(*it2)))==Table.end()){
			cout<<"\t";

		}
		else
		{
			cout<<(*it1)<<"=>"<<Table[mp((*it1),(*it2))]<<" ";
		}
		it2++;
		}

		cout<<endl;
		it1++;
	}
}


void parse(string str){
	stack<string> s;
	s.push("$");
	s.push("S");
	int i=0;
	while(!s.empty()){
		printStack(s);
		cout<<"ip symbol "<<str[i]<<endl;
		string tp = s.top();
		if(tp==eps){
			s.pop();
			continue;
		}
		string ip = toStr(str[i]);

		if(tp==ip){
			cout<<"matched\n";
			s.pop();
			i++;
		}
		else
		{
			if(isTerminal(tp))
			{
				cout<<"Not matched\n";
				return;
			}
			else
			{
				s.pop();
				string pd = Table[mp(tp,ip)];
				if(pd==eps){
					s.push(eps);
					continue;
				}

				reverse(pd.begin(), pd.end());
				for(int j=0;j<pd.length();j++)
					s.push(toStr(pd[j]));
			}
		}
		sleep(0.3);
	}
}

void printStack(stack<string> s){
	cout<<"The stack\n";
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	cout<<"inputting the productions\n";
	inputProductions();

	cout<<"Printing the initial productions\n";
	printProductions(Prod);

	cout<<"Computing First\n";
	computeFirstWrapper();

	cout<<"The first is \n";
	printSetMap(First);

	cout<<"Computing Follow\n";
	computeFollowWrapper();

	cout<<"The follow is \n";
	printSetMap(Follow);

	cout<<"Constructing the table\n";
	constructTable();

	cout<<"Give input to parse\n";
	string ip;
	cin>>ip;
	ip+="$";
	parse(ip);

	return 0;
}