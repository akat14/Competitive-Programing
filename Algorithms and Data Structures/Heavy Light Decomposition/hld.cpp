#include<bits/stdc++.h>
using namespace std;
vector<int>heavy,level,father,head,pos,cost;
vector<vector<pair<int,int>>>adj;
vector<SegmentTree<int>>T;
int dfs(int x,int p)
{
	level[x]=level[p]+1;
	father[x]=p;
	int ma=0,cur,size=1;
	for(auto y:adj[x])
	{
		if(y.first!=p)
		{
			cur=dfs(y.first,x);
			if(ma<cur)
			{
				ma=cur;
				heavy[x]=y.first;
			}
			size+=cur;
		}
		else cost[x]=y.second;
	}
	return size;
}
int hld(int x,int p,int size)
{
	if(size==0)head[x]=x;
	else head[x]=head[p];
	pos[x]=size;
	for(auto y:adj[x])
		if(y.first!=p && y.first!=heavy[x])hld(y.first,x,0);
	if(heavy[x]!=-1)heavy[x]=hld(heavy[x],x,size+1);
	else
	{
		heavy[x]=T.size();
		T.push_back(SegmentTree<int>(size));
	}
	if(pos[x]!=0)T[heavy[x]].update(pos[x]-1,cost[x]);
	return heavy[x];
}
void query(int a,int b)
{
	int ans=0;
	while(heavy[a]!=heavy[b])
	{
		if(level[head[a]]<level[head[b]])swap(a,b);
		if(pos[a])ans=max(ans,T[heavy[a]].query(0,pos[a]-1));
		ans=max(ans,cost[head[a]]);
		a=father[head[a]];
	}
	if(level[a]>level[b])swap(a,b);
	if(a!=b)ans=max(ans,T[heavy[a]].query(pos[a],pos[b]-1));
	cout<<ans<<'\n';
}
void update(int a,int b,int c)
{
	if(father[a]!=b)swap(a,b);
	cost[a]=c;
	if(pos[a])T[heavy[a]].update(pos[a]-1,c);
}
void solve()
{
	int n,i,c;
	cin>>n;
	vector<int>a(n-1),b(n-1);
	heavy=vector<int>(n,-1);
	level=vector<int>(n);
	father=vector<int>(n);
	head=vector<int>(n);
	pos=vector<int>(n);
	cost=vector<int>(n);
	adj=vector<vector<pair<int,int>>>(n);
	for(i=0;i<n-1;i++)
	{
		cin>>a[i]>>b[i]>>c;
		a[i]--;
		b[i]--;
		adj[a[i]].push_back({b[i],c});
		adj[b[i]].push_back({a[i],c});
	}
	dfs(0,0);
	hld(0,0,0);
}

