#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e3,MAXM=2e3;
int dp[MAXM];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,i,j,w,c,ans;
	cin>>m>>n;
	while(m!=0 || n!=0)
	{
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
		{
			cin>>w>>c;
			for(j=m;j>w;j--)
				if(dp[j-w])dp[j]=max(dp[j],dp[j-w]+c);
			dp[w]=max(dp[w],c);
		}
		ans=0;
		for(i=1;i<=m;i++)
			if(dp[ans]<dp[i])ans=i;
		cout<<ans<<" "<<dp[ans]<<'\n';
		cin>>m>>n;
	}
}
