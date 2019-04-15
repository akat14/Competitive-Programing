#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e5+1;
vector<pair<int,int> >ans;
struct warehouse
{
	int x;
	int y;
	int t;
	int i;
}a[MAXN];
bool cmp(warehouse a,warehouse b)
{
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,i;
	cin>>n;
	for(i=0;i<2*n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].i=i+1;
		a[i].t=(i>=n);
	}
	sort(a,a+2*n,cmp);
	int j;
	for(j=1;a[j].t==a[0].t;j++){}
	for(i=0;i<j;i++)
		ans.push_back({a[i].i,a[j].i});
	int last[2];
	last[a[j].t]=a[j].i;
	last[a[j-1].t]=a[j-1].i;
	for(i=j+1;i<2*n;i++)
	{
		ans.push_back({a[i].i,last[a[i].t^1]});
		last[a[i].t]=a[i].i;
	}
	n=ans.size();
	cout<<n<<'\n';
	for(i=0;i<n;i++)
		cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}
