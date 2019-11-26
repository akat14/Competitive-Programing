#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>c;
int ans;
void dfs(int x,int cc,int  oc)
{
	int l=0;
	c[x]=cc;
	int mc=0,i,y;
	for(i=0;i<(int)adj[x].size();i++)
	{
		y=adj[x][i];
		if(c[y]==cc)l=1;
		if(c[y] && mc==0)mc=i;
	}
	if(l)cc=c[x]=6-cc-oc;
	ans=max(ans,c[x]);
	for(i=0;i<(int)adj[x].size();i++)
	{
		y=adj[x][i];
		if(y>x)break;
		if(!c[y])dfs(y,oc,cc);
	}
	for(i=adj[x].size()-1;i>=0;i--)
	{
		y=adj[x][i];
		if(y<x)break;
		if(!c[y])dfs(y,oc,cc);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,a,b,i;
	cin>>n>>m;
	adj.resize(n);
	c.resize(n,0);
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		a--;
		b--;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	for(i=0;i<n;i++)
		sort(adj[i].begin(),adj[i].end());
	for(i=0;i<n;i++)
		if(c[i]==0)dfs(i,1,2);
	cout<<ans<<'\n';
	for(i=0;i<n;i++)
		cout<<c[i]<<" \n"[i==n-1];
}
