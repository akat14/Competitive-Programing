#include<bits/stdc++.h>
#include "Sgame.h"
using namespace std;
const int STN=5e5+1;
struct SegmentTree
{
	int n;
	int it[1<<20];
	SegmentTree()
	{
		n=0;
	}
	void init(int nn)
	{
		n=nn;
	}
	SegmentTree(int nn)
	{
		init(nn);
	}
	int combine(const int &l,const int &r)
	{
		return max(l,r);
	}
	void up(int x,int l,int r,const int &L,const int &R,const int &U)
	{
		if(L<=l && r<=R)
		{
			it[x]=U;
			return;
		}
		if(L<=(l+r)/2)up(x*2,l,(l+r)/2,L,R,U);
		if(R>(l+r)/2)up(x*2+1,(l+r)/2+1,r,L,R,U);
		it[x]=combine(it[x*2],it[x*2+1]);
	}
	void update(int l,int r,int u)
	{
		up(1,0,n-1,l,r,u);
	}
	int qu(int x,int l,int r,int L,int R)
	{
		if(L<=l && r<=R)return it[x];
		int ansl,ansr;
		int f=0;
		if(L<=(l+r)/2)
		{
			f|=1;
			ansl=qu(x*2,l,(l+r)/2,L,R);
		}
		if(R>(l+r)/2)
		{
			f|=2;
			ansr=qu(x*2+1,(l+r)/2+1,r,L,R);
		}
		if(f==1)return ansl;
		if(f==2)return ansr;
		return combine(ansl,ansr);
	}
	int query(int l,int r)
	{
		return qu(1,0,n-1,l,r);
	}
};
struct SuffixAutomata
{
	static const int N=1e6;
	unordered_map<char,int>adj[N];
	int len[N],fail[N],matches[N],cntf[N],used[N],ans[N];
	int n,last;
	SuffixAutomata(int max)
	{
		n=1;
		last=0;
		for(int i=0;i<2*max;i++)
			len[i]=fail[i]=matches[i]=cntf[i]=used[i]=ans[i]=0;
	}
	void dfs(int x)
	{
		used[x]=1;
		bool l=1;
		for(auto y:adj[x])
		{
			if(!used[y.second])dfs(y.second);
			if(matches[x]==matches[y.second])l=0;
		}
		if(l)ans[len[x]]=max(ans[len[x]],matches[x]);
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
	void bfs()
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
SegmentTree T(STN);
int round(int m,int k)
{
	return T.query(m,k);
}
void start(char w[])
{
	int i=0;
	string s="";
	while(w[i]!='\0')
		s+=w[i++];
	SuffixAutomata A(s.size());
	A.build(s);
	A.bfs();
	A.dfs(0);
	for(i=1;i<=(int)s.size();i++)
		T.update(i,i,A.ans[i]);
}
