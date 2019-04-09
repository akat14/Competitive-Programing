#include<iostream>
using namespace std;
const int MAXN=56;
long long dp[2][MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i,n;
	cin>>n;
	dp[0][1]=dp[0][2]=1;
	for(i=3;i<=n;i++)
	{
		dp[0][i]=dp[0][i-1]+dp[1][i-1];
		dp[1][i]=dp[0][i-2];
	}
	long long ans=dp[0][n]+dp[1][n];
	for(i=1;i<n-2;i++)
		ans+=dp[0][i];
	cout<<ans<<'\n';
}
