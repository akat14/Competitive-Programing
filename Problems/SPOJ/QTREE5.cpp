#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1,LGN=20;
vector<int>adj[N];
int sz[N],used[N],father[N],szt,spt[LGN][2*N],level[2*N],ver[2*N],id[N],lg[2*N];
int szdfs(int x,int p)
{
   	sz[x]=1;
  	for(int y:adj[x])
   		if(!used[y] && y!=p)
   			sz[x]+=szdfs(y,x);
 	return sz[x];
}
int cen(int x,int p)
{
   	for(int y:adj[x])
   		if(!used[y] && y!=p && sz[y]>szt/2)
   			return cen(y,x);
  	return x;
}
int centroid_decomposition(int x)
{
   	szt=szdfs(x,x);
   	int centroid=cen(x,x);
   	used[centroid]=1;
   	for(int y:adj[centroid])
   		if(!used[y])
   		{
   			int z=centroid_decomposition(y);
   			father[z]=centroid;
   		}
   	return centroid;
}
void dfs(int x,int p,int l)
{
   	static int cnt=0;
   	level[cnt]=l;
   	ver[cnt]=x;
   	id[x]=cnt++;
   	for(int y:adj[x])
   		if(y!=p)
   		{
   			dfs(y,x,l+1);
   			level[cnt]=l;
   			ver[cnt++]=x;
 		}
}
void build_spt(int n)
{
   	int i,j;
   	lg[1]=0;
   	for(i=2;i<=2*n;i++)
   	{
   		lg[i]=lg[i-1];
   		if((i&(i-1))==0)lg[i]++;
   	}
   	for(i=0;i<2*n;i++)
   		spt[0][i]=i;
   	for(i=1;i<=lg[2*n];i++)
   		for(j=0;j+(1<<i)-1<2*n;j++)
   			if(level[spt[i-1][j]]<level[spt[i-1][j+(1<<(i-1))]])
   				spt[i][j]=spt[i-1][j];
  			else spt[i][j]=spt[i-1][j+(1<<(i-1))];
}
int lca(int x,int y)
{
   	if(id[x]>id[y])swap(x,y);
   	int d=id[y]-id[x]+1;
   	int l=spt[lg[d]][id[x]],r=spt[lg[d]][id[y]-(1<<lg[d])+1];
  	if(level[l]<level[r])return ver[l];
 	return ver[r];
}
int dist(int x,int y)
{
   	return level[id[x]]+level[id[y]]-2*level[id[lca(x,y)]];
}
multiset<int>s[N];
void inse(int st)
{
   	int x=st;
   	while(x!=0)
   	{
   		s[x].insert(dist(st,x));
   		x=father[x];
   	}
}
void era(int st)
{
   	int x=st;
   	while(x!=0)
   	{
   		auto it=s[x].find(dist(st,x));
   		s[x].erase(it);
  		x=father[x];
 	}
}
void find(int st)
{
   	int x=st,ans=-1,cur;
   	while(x!=0)
   	{
   		if(s[x].size())
   		{
   			auto it=s[x].begin();
   			cur=*it+dist(st,x);
   			if(ans==-1 || ans>cur)ans=cur;
   		}
   		x=father[x];
   	}
   	cout<<ans<<'\n';
}
int main()
{
   	ios_base::sync_with_stdio(0);
   	cin.tie(0);
   	int n,a,b,i;
   	cin>>n;
   	for(i=1;i<n;i++)
   	{
   		cin>>a>>b;
   		adj[a].emplace_back(b);
   		adj[b].emplace_back(a);
   	}
   	dfs(1,1,1);
   	build_spt(n);
   	int root=centroid_decomposition(1);
   	father[root]=0;
   	int q;
   	cin>>q;
   	memset(used,0,sizeof(used));
   	for(i=0;i<q;i++)
   	{
   		cin>>a>>b;
   		if(a==0)
   		{
   			if(!used[b])inse(b);
   			else era(b);
   			used[b]^=1;
   		}
   		else find(b);
  	}
}
