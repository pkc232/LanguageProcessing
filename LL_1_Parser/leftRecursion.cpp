#include <bits/stdc++.h>
#define ITR1 map<string,vector<string> >::iterator 
#define ITR2 map<char,triePtr>::iterator 
#define prodn map<string,vector<string> >
#define triePtr trieNode*
#define pb push_back
#define mp make_pair
using namespace std;

string eps = "\u03B5";

prodn oldProd,newProd;
//oldprod stores the production with left recursion

void inputProductions(){
	string left,right;
	cout<<"Enter the rules 0 to exit\n";
	while(1){
		cin>>left;
		if(left=="0")
			break;
		cin>>right;
		oldProd[left].pb(right);
	}
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


string removePrefix(string &s1,string &s2){
	string st = s1.substr(s2.length());
	return st;
}


void removeImmediateLeftRecursion(string S){
	newProd[S].clear();
	vector<string> rts = oldProd[S];
	vector<string> sameSt,diffSt;
	for(int i=0;i<rts.size();i++){
		if(beginSame(rts[i],S))
			sameSt.pb(rts[i]);
		else
			diffSt.pb(rts[i]);
	}
	if(sameSt.size()==0){
		newProd[S]=oldProd[S];
		return;
	}
	else
	{
		string temp="";
		string newLeft=S;
		newLeft+="\'";
		for(int i=0;i<diffSt.size();i++){
			temp=diffSt[i];
			temp+=newLeft;
			newProd[S].pb(temp);
		}
		for(int i=0;i<sameSt.size();i++){
			temp=removePrefix(sameSt[i],S);
			temp+=newLeft;
			newProd[newLeft].pb(temp);
		}
		newProd[newLeft].pb(eps);
		// oldProd[S]=newProd[S];

	}
}


string minusPrefix(string s1,string s2){
	int l = s2.size();

	return s1.substr(l);
}


void replace(ITR1 it1,ITR1 it2){
	string Ai = it1->first;
	string Aj = it2->first;
	vector<string> v1= it1->second;
	vector<string> v2 = it2->second;
	newProd[Ai].clear();
	vector<string> beginAj;
	for(int i=0;i<v1.size();i++){
		if(beginSame(v1[i],Aj)){
			beginAj.pb(v1[i]);
		}
		else
			newProd[Ai].pb(v1[i]);
	}
	for(int i=0;i<beginAj.size();i++){
		string s = beginAj[i];

		for(int j=0;j<oldProd[Aj].size();j++){
			string temp = minusPrefix(s,Aj);
			string temp2 = oldProd[Aj][j];
			temp2+=temp;
			newProd[Ai].pb(temp2);
		}
	}

	oldProd[Ai]=newProd[Ai];
}


void removeLeftRecursion(){
	ITR1 it = oldProd.begin();
	while(it!=oldProd.end()){
		ITR1 it2 = oldProd.begin();
		while(it2!=it){
			replace(it,it2);
			it2++;
		}
		removeImmediateLeftRecursion(it->first);
		it++;
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
			// cout<<it->first<<" : "<<v[i]<<endl;
			if(!beginSame(v[i],eps)||v[i]==eps)
			cout<<v[i]<<" |  ";
			else{
				cout<<minusPrefix(v[i],eps)<<" |  ";
			}
			done.insert(v[i]);
		}
		cout<<endl<<endl;
		it++;
	}
}



int main(int argc, char const *argv[])
{
	cout<<"inputting the productions\n";
	inputProductions();

	cout<<"Printing the initial productions\n";
	printProductions(oldProd);

	cout<<"Removing LEft Recursion\n";
	removeLeftRecursion();

	cout<<"Printing productions OLD \n";
	printProductions(oldProd);

	cout<<"Printing productions NEW\n";
	printProductions(newProd);

	return 0;
}