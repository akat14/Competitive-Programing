#include<bits/stdc++.h>
using namespace std;
void solve()
{
  int n,i;
  cin>>n;
  vector<int>a(n),b(n);
  for(int &x:a)
    cin>>x;
  for(int &x:b)
    cin>>x;
  long long x=0,y=0,br=0,f=1;
  for(int i=0;i<n;i++)
  {
      if(a[i]>=b[i] && f)f=0,x=a[i]-b[i];
      else if(a[i]>=b[i])x=min(x,(long long)(a[i]-b[i]));
      else br++,y=b[i]-a[i];
  }
  if(br>1 || y>x)cout<<"NO\n";
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
