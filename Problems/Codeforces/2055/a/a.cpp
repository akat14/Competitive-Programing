#include<bits/stdc++.h>
using namespace std;
void solve()
{
  int n,a,b;
  cin>>n>>a>>b;
  if(b<a)swap(a,b);
  if((b-a)&1)cout<<"NO\n";
  else cout<<"YES\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)
		solve();
}
