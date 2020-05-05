#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
bool cmp(pair<long long,long long>x,pair<long long,long long>y)
{
	if(x.first != y.first)
		return x.first < y.first;
	return x.second > y.second;
}
long long dp[N],br[N],a[N],b[N];
pair<long long, long long>p[N];
double inter(long long i,long long j)
{
	double ra=a[i]-a[j],rb=b[j]-b[i];
	return rb/ra;
}
long long better(long long i,long long j)
{
	return inter(i,j)+1;
}
long long check(long long charge,long long n)
{
	long long i,j=0,cnt=1;
	a[0]=2-2*p[0].first;
	b[0]=p[0].first*(p[0].first-2)+1;
	br[0]=0;
	for(i=0;i<n;i++)
	{
		while(j+1<cnt && p[i].second>=better(j,j+1))
			j++;
		dp[i+1]=p[i].second*(p[i].second+a[j])+b[j]+charge;
		long long x=0;
		br[cnt]=br[j]+1;
		if(i==n-1)break;
		if(p[i].second >= p[i+1].first)
			x = (p[i].second-p[i+1].first+1)*(p[i].second-p[i+1].first+1);
		a[cnt]=2-2*p[i+1].first;
		b[cnt]=dp[i+1]+p[i+1].first*(p[i+1].first-2)+1-x;
		while(cnt>j+1 && inter(cnt-2,cnt)<inter(cnt-2,cnt-1))
		{
			a[cnt-1]=a[cnt];
			b[cnt-1]=b[cnt];
			br[cnt-1]=br[cnt];
			cnt--;
		}
		cnt++;
	}
	return br[cnt];
}
long long take_photos(long long n,long long m,long long k,long long *r,long long *c)
{
	long long i;
	for(i=0;i<n;i++)
		p[i]={min(r[i],c[i]),max(r[i],c[i])};
	sort(p,p+n,cmp);
	long long cnt=1;
	for(i=1;i<n;i++)
		if(p[i].second>p[cnt-1].second)p[cnt++]=p[i];
	n=cnt;
	k=min(k,n);
	long long l=1, ri=m*m, mid;
	while(l <= ri)
	{
		mid = (l+ri) >> 1;
		long long b = check(mid,n);
		if(b > k)l = mid + 1;
		else ri = mid - 1;
	}
	check(ri+1,n);
	return (dp[n] - (ri+1) * k);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n,m,k,r[N],c[N],i;
	cin>>n>>m>>k;
	for(i=0;i<n;i++)
		cin>>r[i]>>c[i];
	cout<<take_photos(n,m,k,r,c)<<'\n';
}
