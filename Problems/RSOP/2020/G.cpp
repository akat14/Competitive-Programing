#include<bits/stdc++.h>
using namespace std;
const int K=191,MOD=100000007;
long long cnt;
map<pair<long long,long long>,long long>m;
long long get(pair<long long,long long>x)
{
	auto it=m.find(x);
	if(it==m.end())
	{
		m[x]=cnt;
		return cnt++;
	}
	return it->second;
}
long long ma[K*2][K*2],ans[K*2][K*2],h[K*2][K*2];
void pow(long long x)
{
	int i,j,k;
	for(i=0;i<cnt;i++)
		ans[i][i]=1;
	for(;x;x>>=1)
	{
		if(x&1)
		{
			memset(h,0,sizeof(h));
			for(i=0;i<cnt;i++)
				for(k=0;k<cnt;k++)
					for(j=0;j<cnt;j++)
						h[i][j]=(h[i][j]+(ans[i][k]*ma[k][j])%MOD)%MOD;
			for(i=0;i<cnt;i++)
				for(j=0;j<cnt;j++)
					ans[i][j]=h[i][j];
		}
		memset(h,0,sizeof(h));
		for(i=0;i<cnt;i++)
			for(k=0;k<cnt;k++)
				for(j=0;j<cnt;j++)
					h[i][j]=(h[i][j]+(ma[i][k]*ma[k][j])%MOD)%MOD;
		for(i=0;i<cnt;i++)
			for(j=0;j<cnt;j++)
				ma[i][j]=h[i][j];
	}
}
void solve()
{
	cnt=0;
	m.clear();
	memset(ma,0,sizeof(ma));
	memset(ans,0,sizeof(ans));
	long long k,l,q,i,a,b,x,y;
	cin>>k;
	for(i=0;i<k;i++)
	{
		cin>>x>>y;
		a=get({x,y});
		cin>>x>>y;
		b=get({x,y});
		ma[a][b]++;
		ma[b][a]++;
	}
	cin>>l>>q;
	pow(l);
	for(i=0;i<q;i++)
	{
		cin>>x>>y;
		a=get({x,y});
		cin>>x>>y;
		b=get({x,y});
		cout<<ans[a][b]<<'\n';
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long t;
	cin>>t;
	while(t--)
		solve();
}
