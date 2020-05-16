#include<bits/stdc++.h>
using namespace std;
const int N=2e3+1;
long long a[N],mi[2*N],br[2*N],cnt;
vector<long long>adj[N];
void init(long long x,long long l,long long r)
{
	mi[x]=l;
	for(int i=l;i<r;i++)
		if(a[mi[x]]>a[i])mi[x]=i;
	br[x]=1;
	if(mi[x]!=l)
	{
		adj[x].emplace_back(cnt);
		init(cnt++,l,mi[x]);
		br[x]+=br[adj[x].back()];
	}
	if(mi[x]+1!=r)
	{
		adj[x].emplace_back(cnt);
		init(cnt++,mi[x]+1,r);
		br[x]+=br[adj[x].back()];
	}
}
long long better(long long l,long long r)
{
	if(l==-1)return r;
	if(r==-1)return l;
	return min(l,r);
}
long long memo[2*N][N];
long long check(long long x,long long m)
{
	if(m==0)return 0;
	if(memo[x][m])return memo[x][m];
	if(m==1)return memo[x][m]=a[mi[x]];
	if(adj[x].size()==1)return memo[x][m]=check(adj[x][0],m-1);
	long long i,lans,rans;
	long long ans=-1,cur;
	for(i=max(m-br[adj[x][1]],1ll);i<min(br[adj[x][0]]+2,m+1);i++)
	{
		lans=check(adj[x][0],i-1);
		rans=check(adj[x][1],m-i);
		cur=lans+rans;
		if(m!=i && i!=1)cur-=a[mi[x]];
		if(lans==-1 || rans==-1)cur=-1;
		if(ans==-1 || ans>cur)ans=cur;
	}
	return memo[x][m]=ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n,k,i;
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>a[i];
	cnt=1;
	init(0,0,n);
	int l=0,r=n,m;
	while(l<=r)
	{
		m=(l+r)>>1;
		if(check(0,m)<=k)l=m+1;
		else r=m-1;
	}
	cout<<l-1<<'\n';
}
