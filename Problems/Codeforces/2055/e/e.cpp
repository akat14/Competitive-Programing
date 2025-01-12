#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<long long,long long>x,pair<long long,long long> y)
{
  return x.second<y.second;
}
void solve()
{
  long long n,i,sumx=0,sumy=0,ans=0;
  cin>>n;
  vector<pair<long long,long long>>a(n),b;
  for(i=0;i<n;i++)
  {
      cin>>a[i].first>>a[i].second;
      sumx+=a[i].first;
      sumy+=a[i].second;
  }
  sort(a.begin(),a.end(),cmp);
  if(sumy-a[1].second>=sumx)b.push_back(a[0]);
  else ans+=a[0].first;
  for(i=1;i<n;i++)
    if(sumy-a[0].second>=sumx)b.push_back(a[i]);
    else ans+=a[i].first;
  if(b.size()==0)
  {
    cout<<"-1\n";
    return;
  }
  sort(b.begin(),b.end());
  long long csum=0;
  for(i=0;i<b.size();i++)
  {
    if(csum>b[i].first)
    {
        ans+=b[i].first;
        csum-=b[i].first;
    }
    else ans+=(b[i].first-csum)*2+csum,csum=0;
    csum+=b[i].second;
    cout<<i<<" "<<b[i].first<<" "<<b[i].second<<" "<<ans<<" "<<csum<<endl;
  }
  cout<<ans<<'\n';
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
