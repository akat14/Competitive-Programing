#include<bits/stdc++.h>
using namespace std;
const int MAXN=;
vector<int>v[MAXN];
int f,p,ans[MAXN],used[MAXN];
void dfs(int x)
{
	int i,n=v[x].size();
	used[x]=1;
	for(i=0;i<n;i++)
	{
		if(used[v[x][i]]==1)f=1;
		if(!used[v[x][i]])dfs(v[x][i]);
	}
	used[x]=2;
	ans[p++]=x;
}
int main()
{
	int n,m,i,x,y;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(i=1;i<=n;i++)
		if(!used[i])dfs(i);
	if(f)cout<<"Impossible.\n";
	else
	{
		for(i=p-1;i>0;i--)
			cout<<ans[i]<<" ";
		cout<<ans[i]<<'\n';
	}
}
