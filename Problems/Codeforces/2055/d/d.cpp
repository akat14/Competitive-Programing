#include<bits/stdc++.h>
using namespace std;
void solve()
{
  long long n,k,l,nc,na;
  cin>>n>>k>>l;
  l*=2;
  k*=2;
  vector<long long>a(n);
  for(auto &x:a)
  {
    cin>>x;
    x*=2;
  }
  long long c=0,ans=0;
  ans+=a[0];
  c=k;
  for(int i=1;i<n;i++)
  {
    if(c>=l)break;
    if(a[i]-ans<=c)
    {
        if(a[i]+ans>=c)c+=k;
        else c=a[i]+ans+k;
        continue;
    }
    a[i]-=ans;
    na=(a[i]-c)/2;
    if(na+c>=l)
    {
      cout<<ans+l-c<<'\n';
      return;
    }
    ans+=na;
    c+=na+k;
  }
  if(c>=l)cout<<ans<<'\n';
  else cout<<ans+l-c<<'\n';
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
