#include<bits/stdc++.h>
using namespace std;
const int N=201;
const double eps=1e-7;
double d[N];
int father[N];
pair<int,double>find(int x)
{
	if(x==father[x])return {x,0.0};
	auto y=find(father[x]);
	return {y.first,y.second+d[x]};
}
void solve()
{
	int n,m,i,l,r;
	double a;
	cin>>n>>m;
	for(i=0;i<=n;i++)
	{
		d[i]=-1;
		father[i]=i;
	}
	int ans=1,br=0;
	for(i=0;i<m;i++)
	{
		cin>>l>>r>>a;
		if(l>r)swap(l,r);
		if(l==r && a>eps)ans=2;
		auto x=find(l);
		auto y=find(r);
		if(x.first==y.first)
		{
			if(x.first<l)
			{
				if(abs(y.second-a-x.second)>eps)ans=2;
			}
			else if(x.first<r)
			{
				if(abs(a-x.second-y.second)>eps)ans=2;
			}
			else if(abs(x.second-a-y.second)>eps)ans=2;
		}
		else
		{
			br++;
			if(x.first<y.first)
			{
				father[y.first]=x.first;
				d[y.first]=abs(x.second+a-y.second);
			}
			else
			{
				father[x.first]=y.first;
				d[x.first]=abs(y.second-a-x.second);
			}
		}
	}
	vector<double>as;
	for(i=1;i<n;i++)
	{
		auto x=find(i);
		auto y=find(i+1);
		double p;
		if(x.first<i)p=y.second-x.second;
		else if(x.first>i+1)p=x.second-y.second;
		else p=x.second+y.second;
		as.push_back(p);
		if(p<-eps)ans=2;
	}
	if(br!=n-1)ans=2;
	cout<<ans<<'\n';
	if(ans==2)return;
	for(i=0;i<n-1;i++)
	{
		cout<<setprecision(3)<<as[i];
		if(i+2!=n)cout<<' ';
	}
	cout<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed; 
	int t;
	cin>>t;
	while(t--)
		solve();
}
