#include<bits/stdc++.h>
using namespace std;
vector<int>heavy,level,father,head;
vector<vector<int>>adj;
vector<bool>used;
vector<priority_queue<pair<int,int>>>T;
int dfs(int x,int p=-1)
{
	if(p!=-1)level[x]=level[p]+1;
	father[x]=p;
	int ma=0,cur,size=1;
	for(auto y:adj[x])
	{
		if(y!=p)
		{
			cur=dfs(y,x);
			if(ma<cur)
			{
				ma=cur;
				heavy[x]=y;
			}
			size+=cur;
		}
	}
	return size;
}
int hld(int x,int p=-1,int size=0)
{
	static int cnt=0;
	if(size==0)head[x]=x;
	else head[x]=head[p];
	for(auto y:adj[x])
		if(y!=p && y!=heavy[x])hld(y,x);
	if(heavy[x]!=-1)heavy[x]=hld(heavy[x],x,size+1);
	else heavy[x]=cnt++;
	return heavy[x];
}
void query(int x)
{
	int ans=-2,cans=-2;
	while(x!=-1)
	{
		while(T[heavy[x]].size() && !used[T[heavy[x]].top().second])
			T[heavy[x]].pop();
		if(T[heavy[x]].size())cans=T[heavy[x]].top().second;
		if(level[x]>=level[cans])ans=cans;
		x=father[head[x]];
	}
	cout<<ans+1<<'\n';
}
void update(int x)
{
	used[x]=used[x]^1;
	if(used[x])T[heavy[x]].push({-level[x],x});
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q,i,a,b;
	cin>>n>>q;
	heavy=vector<int>(n,-1);
	level=vector<int>(n);
	father=vector<int>(n);
	head=vector<int>(n);
	adj=vector<vector<int>>(n);
	used=vector<bool>(n);
	for(i=0;i<n-1;i++)
	{
		cin>>a>>b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	dfs(0);
	int sz=hld(0)+1;
	T.resize(sz);
	for(i=0;i<q;i++)
	{
		cin>>a>>b;
		if(a)query(b-1);
		else update(b-1);
	}
}

