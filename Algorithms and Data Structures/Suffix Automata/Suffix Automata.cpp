#include<bits/stdc++.h>
using namespace std;
struct SuffixAutomata
{
	vector<unordered_map<char,int>>adj;
	vector<int>len,fail,matches,cntf;
	int n,last;
	SuffixAutomata(int max)
	{
		n=1;
		last=0;
		len=fail=matches=cntf=used=vector<int>(2*max+1,0);
		adj=vector<unordered_map<char,int>>(2*max+1);
	}
	void add_char(char c)
	{
		int cur=n++,p,q;
		len[cur]=len[last]+1;
		matches[cur]=1;
		p=last;
		while(!adj[p][c])
		{
			adj[p][c]=cur;
			p=fail[p];
		}
		q=adj[p][c];
		if(adj[p][c]==cur)fail[cur]=0;
		else if(len[p]+1==len[q])fail[cur]=q;
		else
		{
			int copy=n++;
			matches[copy]=0;
			adj[copy]=adj[q];
			len[copy]=len[p]+1;
			fail[copy]=fail[q];
			fail[cur]=fail[q]=copy;
			cntf[copy]++;
			while(adj[p][c]==q)
			{
				adj[p][c]=copy;
				p=fail[p];
			}
		}
		cntf[fail[cur]]++;
		last=cur;
	}
	void build(string &s)
	{
		for(char c:s)
			add_char(c);
	}
	void find_matches()
	{
		queue<int>q;
		for(int i=0;i<n;i++)
			if(!cntf[i])q.push(i);
		while(q.size())
		{
			int x=q.front();
			q.pop();
			matches[fail[x]]+=matches[x];
			cntf[fail[x]]--;
			if(!cntf[fail[x]])q.push(fail[x]);
		}
	}
};