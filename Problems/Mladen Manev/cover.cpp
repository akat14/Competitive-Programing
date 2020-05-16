#include<bits/stdc++.h>
using namespace std;
struct SuffixAutomata
{
	vector<unordered_map<char,int>>adj;
	vector<int>len,fail,lon,ans,start;
	int n,last;
	SuffixAutomata(int max)
	{
		n=1;
		last=0;
		len=fail=lon=start=vector<int>(2*max+1,0);
		adj=vector<unordered_map<char,int>>(2*max+1);
	}
	void add_char(char c)
	{
		int cur=n++,p,q;
		len[cur]=len[last]+1;
		start[cur]=ans.size();
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
			start[copy]=start[q];
			lon[copy]=min(lon[q],len[copy]);
			fail[copy]=fail[q];
			fail[cur]=fail[q]=copy;
			while(adj[p][c]==q)
			{
				adj[p][c]=copy;
				p=fail[p];
			}
		}
		int longest=len[fail[cur]];
		int x=start[fail[cur]]-len[fail[cur]]+1;
		if(len[fail[cur]]*2+x>len[cur])
		{
			int l=0,f=0;
			l=(len[cur]-x)%(len[cur]-x-longest);
			longest=(len[cur]-x)/(len[cur]-x-longest);
			if(longest&1)f=1;
			longest/=2;
			longest=longest*(len[cur]-x-len[fail[cur]]);
			if(f)longest+=l;
		}
		lon[cur]=longest=max(longest,lon[fail[cur]]);
		last=cur;
		ans.emplace_back(longest);
	}
	void build(string &s)
	{
		for(char c:s)
			add_char(c);
	}
};
int main()
{
	string s,r;
	cin>>s;
	r=s;
	reverse(r.begin(),r.end());
	SuffixAutomata A(s.size()),B(s.size());
	A.build(s);
	B.build(r);
	long long ans=0;
	for(int i=1;i<(int)s.size()-1;i++)
	{
		if(A.ans[i]==0 || B.ans[s.size()-2-i]==0)continue;
		ans+=A.ans[i]*B.ans[s.size()-2-i]-(A.ans[i]-1)*min((B.ans[s.size()-1-i]-1)*(B.ans[s.size()-1-i]>0),B.ans[s.size()-2-i]);
	}
	cout<<ans<<'\n';
}
