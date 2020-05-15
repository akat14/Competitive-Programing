#include<bits/stdc++.h>
using namespace std;
const int W=101;
int dp[W];
void solve()
{
	int w,i,a,j,n;
	cin>>w>>n;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(i=0;i<n;i++)
	{
		cin>>a;
		for(j=w;j-a>=0;j--)
			if(dp[j-a])dp[j]=max(dp[j],dp[j-a]+1);
	}
	if(dp[w])cout<<dp[w]-1<<'\n';
	else cout<<"0\n";
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
