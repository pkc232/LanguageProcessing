#include <bits/stdc++.h>
using namespace std;
struct lr0
{
	set<string> item;
};
typedef struct lr0* lptr;
map<pair<int,string>,string >  actiontable;
map<string,vector<string> > gram;
map<string,set<string> > follow;
string start_symbol;
vector<string> non_terminals;
vector<string> symobols;
map<int,lr0> states;
vector<pair<string,int> > graph[105];
map<set<string>,int > vis;
void BreakGrammar(string start,string s) //Breaking the string into based on | 
{
	for(int i=0;i<s.length();i++)
	{
		string t;
		while(i<s.length() && s[i]!='|')
		{
			t.push_back(s[i]);
			i++;
		}
		gram[start].push_back(t);
	}
}
void TakeInput() //Taking input
{
	int n;
	ifstream fin;
	fin.open("input.txt");
	fin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		fin>>s;
		int pos=s.find("->");
		string start=s.substr(0,pos);
		if(i==0)start_symbol=start;
		s=s.substr(pos+2);
		BreakGrammar(start,s);
	}
}
void FindNonTerminal()
{
	cout<<"Non Terminals\n";
	for(map<string,vector<string> >::iterator it=gram.begin();it!=gram.end();it++)
	{
		non_terminals.push_back(it->first);
		cout<<it->first<<" ";
	}
	cout<<endl;
}
void FindSymbols()
{
	cout<<"Symbols\n";
	set<string> ans;
	for(map<string,vector<string> >::iterator it=gram.begin();it!=gram.end();it++)
	{
		ans.insert(it->first);
		for(int i=0;i<it->second.size();i++)
			for(int j=0;j<it->second[i].length();j++)
			{
				if(it->second[i][j]!='-' && it->second[i][j]!='>' && it->second[i][j]!='|')
					ans.insert(string(1,it->second[i][j]));
			}
	}
	for(set<string>::iterator it=ans.begin();it!=ans.end();it++)
	{	cout<<*it<<" ";
		symobols.push_back(*it);
	}
	cout<<endl;
}
struct lr0 Closure(string item)
{
	struct lr0 ans;
	ans.item.insert(item);
	while(true)
	{
		struct lr0 new_ans=ans;
		for(set<string>::iterator it=ans.item.begin();it!=ans.item.end();it++)
		{
			int pos=(*it).find(".");
			if(pos==(*it).length()-1)continue;
			string X=string(1,(*it)[pos+1]);

			if(gram.find(X)==gram.end())continue;
			for(int i=0;i<gram[X].size();i++)
				new_ans.item.insert(X+"->."+gram[X][i]);
		}
		if(new_ans.item==ans.item)
			break;
		ans=new_ans;
	}
	return ans;
}
void Add(struct lr0 &ans,struct lr0 X)
{
	for(set<string>::iterator it=X.item.begin();it!=X.item.end();it++)
		ans.item.insert(*it);
}
struct lr0 Goto(struct lr0 &I,string X)
{
	
	struct lr0 ans;
	for(set<string>::iterator it=I.item.begin();it!=I.item.end();it++)
	{
		int pos=(*it).find(".");
		if(pos==(*it).length()-1)continue;
		string X2=string(1,(*it)[pos+1]);
		string item_after_readingX=(*it).substr(0,pos)+X2+"."+(*it).substr(pos+2);
		//cout<<"per\n";
		if(X==X2)
			Add(ans,Closure(item_after_readingX));
	}
	return ans;
}
void PrintGram() //Function to print the current grammar 
{
	cout<<"Modified Grammar\n";
	for(map<string,vector<string> >::iterator it=gram.begin();it!=gram.end();it++)
	{
		if(it->second.size()==0)
		{	cout<<it->first<<" eph\n";
			continue;
		}
		cout<<it->first<<" ";
		for(int j=0;j<it->second.size();j++)
			cout<<it->second[j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
void Print(set<string> &item)
{
	for(set<string>::iterator it=item.begin();it!=item.end();it++)
		cout<<*it<<endl;
	cout<<endl;
}
int LR0Auto(struct lr0 &start)
{
	states[0]=start;
	//cout<<states[0]->item.size();
	queue<lr0> Q;
	queue<int> Qstates;
	Q.push(start);
	vis[start.item]=0;
	Qstates.push(0);
	int cnt=0;
	while(!Q.empty())
	{
		lr0 curr=Q.front();Q.pop();
		int curr_state=Qstates.front();Qstates.pop();
		//cout<<"curr\n";
		//Print(curr.item);
		//cout<<"per\n";
		for(int i=0;i<symobols.size();i++)
		{
			struct lr0 next=Goto(curr,symobols[i]);
			if(next.item.size()==0)continue;
			if(vis.find(next.item)==vis.end())
			{
				cnt++;
				states[cnt]=next;
				graph[curr_state].push_back(make_pair(symobols[i],cnt));
				Q.push(next);
				Qstates.push(cnt);
				vis[next.item]=cnt;
			}
			else 
				graph[curr_state].push_back(make_pair(symobols[i],vis[next.item]));
			//Print(curr.item);
			//cout<<symobols[i]<<" next\n";
			//Print(next.item);
		}
	}
	//cout<<cnt<<endl;
	return cnt;
}
void PrintGraph(int cnt)
{
	
	cout<<"LR0 Automaton\n";
	for(int i=0;i<=cnt;i++)
	{
		cout<<"Current State "<<i<<endl;
		//Print(states[i].item);
		cout<<"Adjacent\n";
		for(int j=0;j<graph[i].size();j++)
		{	
			cout<<"State "<<" "<<graph[i][j].first<<" "<<graph[i][j].second<<endl;
			//Print(states[graph[i][j].second].item);
		}
	}
}
void ReduceActions(int u)
{
	for(set<string>::iterator it=states[u].item.begin();it!=states[u].item.end();it++)
	{
		int pos=(*it).find(".");
		if(pos==(*it).length()-1)
		{
			string alpha=string(1,(*it)[0]);
			if((*it)[1]=='\'')alpha.push_back('\'');
			//cout<<u<<" "<<*it<<"per\n";
			for(set<string>::iterator it2=follow[alpha].begin();it2!=follow[alpha].end();it2++)
				actiontable[make_pair(u,*it2)]=(*it).substr(0,pos);
		}
	}
} 
void ShiftActions(int u)
{	
	for(int j=0;j<graph[u].size();j++)
	{	   
		//cout<<u<<" "<<graph[u][j].first<<" "<<graph[u][j].second<<endl;
		pair<int,string> p=make_pair(u,graph[u][j].first);
		string num=to_string(graph[u][j].second);
		actiontable.insert(make_pair(p,num));
		cout<<actiontable[p]<<endl;
	}
}
void SLRConstruction(int vertices)
{
	for(int i=0;i<=vertices;i++)
	{
		ShiftActions(i);
		ReduceActions(i);
	}
}
void PrintTable(int vertices)
{
	cout<<endl;
	//cout<<"SLR Parsing Table\n";
	symobols.push_back("$");
	for(int i=0;i<=vertices;i++)
		for(int j=0;j<symobols.size();j++)
		{
			map<pair<int,string>,string >::iterator it=actiontable.find(make_pair(i,symobols[j]));
			cout<<i<<" "<<symobols[j]<<" ";
			if(it==actiontable.end())
				cout<<"err\n";
			else
				cout<<it->second<<endl;
		}
}
bool isEph(vector<string> &v)//Function to check if ephsilon is present 
{
	for(int i=0;i<v.size();i++)
		if(v[i]=="eph")
			return true;
	return false;
}
void Distinct(vector<string>& ans)//Finds the distinct elements of vector 
{
	set<string> t;
	for(int i=0;i<ans.size();i++)
		t.insert(ans[i]);
	ans.clear();
	for(set<string>::iterator it=t.begin();it!=t.end();it++)
		ans.push_back(*it);
}
vector<string> CalculateFirst(string alpha)
{
	
	if(gram.find(alpha)==gram.end())	//Checking if alpha is non terminal or not 
	{
		vector<string> ans;
		if(alpha[0]<'A' || alpha[0]>'Z' ) //if production start symbol is terminal or ephsilon
		{
			if(alpha!="eph")
			ans.push_back(string(1,alpha[0]));
			else
			ans.push_back("eph");
			return ans;
		}
		int i;
		for(i=0;i<alpha.length() && alpha[i]>='A' && alpha[i]<='Z';)
		{
			string y; //y is a non terminal symbol and followed by dashes(' char)
			y.push_back(alpha[i]);i++;
			while(i<alpha.length() && alpha[i]=='\'')
			{
				y.push_back(alpha[i]);
				i++;
			}
			vector<string> ans1=CalculateFirst(y);
			ans.insert(ans.end(),ans1.begin(),ans1.end());
			if(isEph(ans1)==false) //if non terminal y contains eph then find first for next non terminal
			break;
		}
		if(i<alpha.length())
			ans.push_back(string(1,alpha[i]));

		return ans;
	}

	//cout<<"Calculate First "<<alpha<<endl;
	vector<string> ans;
	//cout<<"per\n";
	for(int j=0;j<gram[alpha].size();j++)
	{
		if(gram[alpha][j]=="eph") // if X->eph is a production in X add it to first(X)
			ans.push_back(gram[alpha][j]);
		else
		{
			if(gram[alpha][j][0]<'A' || gram[alpha][j][0]>'Z') // if rhs of production begins with a terminal
				ans.push_back(string(1,gram[alpha][j][0]));
			else
			{
				//For each production of alpha
				int i; 
				for(i=0;i<gram[alpha][j].length() && gram[alpha][j][i]>='A' && gram[alpha][j][i]<='Z';)
				{
					string y;	//y is a non terminal symbol 
					y.push_back(gram[alpha][j][i]);
					i++;
					while(i<gram[alpha][j].length() && gram[alpha][j][i]=='\'')
					{
						y.push_back(gram[alpha][j][i]);
						i++;
					}
					vector<string> ans1=CalculateFirst(y);
					ans.insert(ans.end(),ans1.begin(),ans1.end());
					if(isEph(ans1)==false)
						break;
				}
				if(i<alpha.length())
					ans.push_back(string(1,alpha[i]));

			}
		}
	}
	//cout<<"Answer\n";
	Distinct(ans);
	//cout<<alpha<<" "<<ans.size()<<endl;
	//for(int i=0;i<ans.size();i++)
		//cout<<ans[i]<<" ";cout<<endl;
	return ans;
}
void union_set(set<string> &s1,set<string> &s2)
{
	for(set<string>::iterator it=s2.begin();it!=s2.end();it++)
		s1.insert(*it);
}
void FollowPreProcess()
{
	//FindNonTerminal();
	while(true)
	{
		map<string,set<string> > new_follow=follow;//Intialise old follow set to new one
		for(int i=0;i<non_terminals.size();i++)//For each non terminal 
			for(int j=0;j<non_terminals.size();j++)//For each production 
				for(int k=0;k<gram[non_terminals[j]].size();k++)//For each element of production 
				{
					if(non_terminals[i]==start_symbol)
							new_follow[non_terminals[i]].insert("$");
					int pos=gram[non_terminals[j]][k].find(non_terminals[i]);//Check if non terminal present in RHS 
					if(pos==-1)continue;
					string beta=gram[non_terminals[j]][k].substr(pos+non_terminals[i].length());
					if(beta.length()!=0 && beta[0]=='\'')continue;
					if(beta.length()!=0 && (beta[0]<'A' || beta[0]>'Z'))//first(beta) is terminal
					{
						new_follow[non_terminals[i]].insert(string(1,beta[0]));
						continue;
					}
					vector<string> ans=CalculateFirst(beta);//Find first(beta)
					for(vector<string>::iterator vit=ans.begin();vit!=ans.end();vit++)
						new_follow[non_terminals[i]].insert(*vit);
					if(isEph(ans)==true || beta.length()==0)	//If first(beta) is terminal add follow(lhs) to new_follow set
						union_set(new_follow[non_terminals[i]],follow[non_terminals[j]]);
				}
		//cout<<endl;
		//cout<<"Print\n";
		//Print(follow);
		//cout<<"per\n";
		//Print(new_follow);
		if(follow==new_follow)
			break;
		follow=new_follow;
	}
	follow["E'"].insert("$");
	//Print(follow);
}
void ParsingAction(string t)
{
	stack<int> S;
	S.push(0);
	for(int i=0;true;)
	{
		int s=S.top();
		map<pair<int,string> ,string >::iterator it;
		it=actiontable.find(make_pair(s,string(1,t[i])));
		if(it==actiontable.end())
		{
			cout<<"error\n";
			break;
		}
		else if(it->second.length()==1)
		{
			S.push(atoi(it->second.c_str()));
			i++;
		}
		else
		{
			if(it->second=="E'->E")
			{
				cout<<"accept\n";
				break;
			}
			int pos=it->second.find(">");
			string beta=it->second.substr(pos+1);
			string A=string(1,it->second[0]);
			for(int j=0;j<beta.length();j++)
				S.pop();
			S.push(atoi(actiontable[make_pair(S.top(),A)].c_str()));
		}
	}
}
int main()
{
	TakeInput();
	FindNonTerminal();
	FollowPreProcess();
	struct lr0 start=Closure("E'->.E");
	Print(start.item);
	FindNonTerminal();
	FindSymbols();

	int vertices=LR0Auto(start);	
	PrintGraph(vertices);
	cout<<endl;
	SLRConstruction(vertices);
	PrintTable(vertices);
	ParsingAction("(i+i*i*i+(i+i)*i)$");
	
	return 0;
}