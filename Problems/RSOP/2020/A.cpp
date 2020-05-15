#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int m,a[N];
bool cmp(int x,int y)
{
	if(x%m==y%m)return x<y;
	return x%m<y%m;
}
void solve()
{
	int n,i;
	cin>>m>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	for(i=0;i<n;i++)
	{
		cout<<a[i];
		if(i+1!=n)cout<<" ";
	}
	cout<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
		solve();
}
