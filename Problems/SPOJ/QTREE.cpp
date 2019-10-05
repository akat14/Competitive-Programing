#include<bits/stdc++.h>
using namespace std;
template<class T>
struct SegmentTree
{
	int n;
	vector<T>it;
	SegmentTree(int nn)
	{
		n=nn;
		it.resize(4*n);
	}
	T conquer(const T &x,const T y)
	{
		return max(x,y);
	}
	void up(int x,int l,int r,const int &I,const int &U)
	{
		if(l==r)
		{
			it[x]=U;
			return;
		}
		if(I>(l+r)/2)up(x*2+1,(l+r)/2+1,r,I,U);
		else up(x*2,l,(l+r)/2,I,U);
		it[x]=conquer(it[x*2],it[x*2+1]);
	}
	void update(int i,int u)
	{
		up(1,0,n-1,i,u);
	}
	T get(int x,int l,int r,const int &L,const int &R)
	{
		if(L<=l && r<=R)return it[x];
		int f=0;
		T ansl,ansr;
		if(L<=(l+r)/2)
		{
			f|=1;
			ansl=get(x*2,l,(l+r)/2,L,R);
		}
		if(R>(l+r)/2)
		{
			f|=2;
			ansr=get(x*2+1,(l+r)/2+1,r,L,R);
		}
		if(f==1)return ansl;
		if(f==2)return ansr;
		return conquer(ansl,ansr);
	}
	T query(int l,int r)
	{
		return get(1,0,n-1,l,r);
	}
};
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
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
	string s;
	int d;
	cin>>s;
	while(s!="DONE")
	{
		cin>>c>>d;
		if(s=="QUERY")query(c-1,d-1);
		else update(a[c-1],b[c-1],d);
		cin>>s;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
}
