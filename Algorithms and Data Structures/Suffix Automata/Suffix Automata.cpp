#include<bits/stdc++.h>
using namespace std;
struct SuffixAutomata
{
	static const int N=;
	unordered_map<char,int>adj[N];
	int len[N],fail[N];
	int n,last;
	SuffixAutomata(int max)
	{
		n=1;
		last=0;
		for(int i=0;i<2*max;i++)
			len[i]=fail[i]=0;
	}
	void add_char(char c)
	{
		int cur=n++,p,q;
		len[cur]=len[last]+1;
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
			adj[copy]=adj[q];
			len[copy]=len[p]+1;
			fail[copy]=fail[q];
			fail[cur]=fail[q]=copy;
			while(adj[p][c]==q)
			{
				adj[p][c]=copy;
				p=fail[p];
			}
		}
		last=cur;
	}
	void build(string &s)
	{
		for(char c:s)
			add_char(c);
	}
};