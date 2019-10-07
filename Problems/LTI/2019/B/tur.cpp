#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>k,sz,ans;
vector<bool>used;
void subtrees(int x,int p)
{
	sz[x]=1;
	for(auto y:adj[x])
	{
		if(!used[y] && y!=p)
		{
			subtrees(y,x);
			sz[x]+=sz[y];
		}
	}
}
pair<int,int>find_centroid(int x,int p,const int &n)
{
	int ma=n-sz[x];
	pair<int,int>ans={n,x};
	for(auto y:adj[x])
	{
		if(!used[y] && y!=p)
		{
			ans=min(ans,find_centroid(y,x,n));
			ma=max(ma,sz[y]);
		}
	}
	return min(ans,{ma,x});
}
void update(int x,int p,int dist)
{
	ans[x]=max(ans[x],dist+k[x]);
	for(auto y:adj[x])
		if(!used[y] && y!=p)update(y,x,dist+k[x]);
}
void centroid_decomposition(int x)
{
	subtrees(x,x);
	if(sz[x]==1)
	{
		ans[x]=k[x];
		return;
	}
	int centroid=find_centroid(x,x,sz[x]).second;
	used[centroid]=1;
	for(auto y:adj[centroid])
		if(!used[y])centroid_decomposition(y);
	used[centroid]=0;
	int i,best=-1,br=0;
	for(i=0;i<(int)adj[centroid].size();i++)
	{
		if(used[adj[centroid][i]])continue;
		if(best==-1 || ans[adj[centroid][best]]<ans[adj[centroid][i]])best=i;
		br++;
	}
	ans[centroid]=ans[adj[centroid][best]]+k[centroid];
	int u=k[centroid];
	if(br>1)
	{
		int secondbest=0;
		for(i=0;i<(int)adj[centroid].size();i++)
			if(best!=i && !used[adj[centroid][i]])
			{
				if(secondbest<ans[adj[centroid][i]])secondbest=ans[adj[centroid][i]];
				update(adj[centroid][i],centroid,ans[centroid]);
			}
		u+=secondbest;
	}
	update(adj[centroid][best],centroid,u);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,i,a,b;
	cin>>n;
	adj=vector<vector<int>>(n);
	for(i=1;i<n;i++)
	{
		cin>>a>>b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int m;
	cin>>m;
	k=vector<int>(n);
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		k[a-1]=b;
	}
	used=vector<bool>(n);
	ans=vector<int>(n);
	sz=vector<int>(n);
	centroid_decomposition(0);
	int t;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>a;
		cout<<ans[a-1]-k[a-1]<<" \n"[i==t-1];
	}
}
