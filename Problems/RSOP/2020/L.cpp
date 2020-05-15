#include<bits/stdc++.h>
using namespace std;
struct SuffixAutomata
{
	vector<map<char,int>>adj;
	vector<int>len,fail,matches,cntf;
	int n,last;
	int anslen;
	string ans;
	vector<int>used;
	SuffixAutomata(int max)
	{
		n=1;
		last=0;
		len=fail=matches=cntf=used=vector<int>(2*max+1,0);
		adj=vector<map<char,int>>(2*max+1);
		anslen=0;
		used=len;
		ans=string(max+1,'?');
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
			if(matches[x]>1)anslen=max(anslen,len[x]);
		}
	}
	bool dfs(int x)
	{
		if(len[x]==anslen && matches[x]>1)return 1;
		used[x]=1;
		for(auto y:adj[x])
		{
			if(!used[y.second] && len[x]+1==len[y.second])
			{
				ans[len[x]]=y.first;
				int l=dfs(y.second);
				if(l)return 1;
			}
		}
		return 0;
	}
	string find()
	{
		dfs(0);
		return ans.substr(0,anslen);
	}
};
void solve()
{
	string s;
	cin>>s;
	SuffixAutomata A(s.size());
	A.build(s);
	A.find_matches();
	cout<<A.find()<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
		solve();
}
