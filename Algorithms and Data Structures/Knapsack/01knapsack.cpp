#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e3,MAXM=2e3;
int dp[MAXM];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,i,j,w,c;
	cin>>n>mn;
	for(i=0;i<n;i++)
	{
		cin>>w>>c;
		for(j=m;j>w;j--)
			if(dp[j-w])dp[j]=max(dp[j],dp[j-w]+c);
		dp[w]=max(dp[w],c);
	}
	int ans=0;
	for(i=1;i<=m;i++)
		ans=max(ans,dp[i]);
	cout<<ans<<'\n';
}
