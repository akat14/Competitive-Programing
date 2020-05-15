#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b,i=20;
	cin>>a>>b;
	while(__gcd(a,i)!=1)
		i++;
	cout<<a/__gcd(a,b)<<" "<<i<<'\n';
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
