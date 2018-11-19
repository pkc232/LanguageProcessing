#include <bits/stdc++.h>
#define ITR1 map<string,vector<string> >::iterator 
#define ITR2 map<char,triePtr>::iterator 
#define prodn map<string,vector<string> >
#define triePtr trieNode*
#define pb push_back
#define mp make_pair
using namespace std;

prodn oldProd,newProd;


struct trieNode{
	char data;
	int isWord;
	map<char,triePtr> ptrs; 
};

void initialize(triePtr &nd,char ch){
	nd->data = ch;
	nd->isWord = 0;
}



void insertInTrie(triePtr root,string &str,int ind,int len){
	if(ind==len){
		root->isWord=1;
		return;
	}


	if(root->ptrs.find(str[ind])==root->ptrs.end()){
		root->ptrs[str[ind]] = new trieNode();
	}

	initialize(root->ptrs[str[ind]],str[ind]);
	insertInTrie(root->ptrs[str[ind]],str,ind+1,len);
}

void assignPrefix(triePtr root,string Left,string PrefixSeen){

	PrefixSeen+=root->data;
	

	if(root->ptrs.size()==0){
		newProd[Left].pb(PrefixSeen);
		return;
	}
	

	if((root->ptrs.size()>1)||(root->ptrs.size()==1&&root->isWord)){
		string newLeft = Left;
		newLeft+="\'";
		string rit = PrefixSeen;
		rit+=newLeft;
		newProd[Left].pb(rit);
		ITR2 it = root->ptrs.begin();
		while(it!=root->ptrs.end()){
			assignPrefix(it->second,newLeft,"");
			it++;
		}
	}
	
	else
	{
		ITR2 it = root->ptrs.begin();
		while(it!=root->ptrs.end()){
			assignPrefix(it->second,Left,PrefixSeen);
			it++;
		}
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
			cout<<v[i]<<" |  ";
			done.insert(v[i]);
		}
		cout<<endl<<endl;
		it++;
	}
}

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

void constructTrie(triePtr &T,vector<string> &v){
	T = new trieNode();

	for(int i=0;i<v.size();i++)
	{
		int l = v[i].length();
		insertInTrie(T,v[i],0,l);
	}


}

void leftFactorTheGrammar(){
	ITR1 it =oldProd.begin();

	while(it!=oldProd.end()){
		string left = it->first;
		vector<string> pds = it->second;
		triePtr T;
		constructTrie(T,pds);
		ITR2 it2 = T->ptrs.begin();
		while(it2!=T->ptrs.end()){
		assignPrefix(it2->second,left,"");
		it2++;
		}
		it++;
	}
}

int main(){
	cout<<"Inputting the productions\n";
	inputProductions();

	cout<<"Printing the productions\n";
	printProductions(oldProd);

	cout<<"Left Factoring the Grammar\n";
	leftFactorTheGrammar();

	cout<<"New productions\n";
	printProductions(newProd);
}