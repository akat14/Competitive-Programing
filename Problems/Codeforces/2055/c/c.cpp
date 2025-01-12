#include<bits/stdc++.h>
using namespace std;
void solve()
{
  long long i,j,n,m,br=0;
  string s;
  cin>>n>>m>>s;
  vector<vector<long long>>v(n,vector<long long>(m));
  vector<long long>r(n,0),c(m,0);
  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    {
      cin>>v[i][j];
      r[i]+=v[i][j];
      c[j]+=v[i][j];
    }
  i=j=0;
  for(char ch:s)
  {
    if(ch=='D')
    {
      v[i][j]=-r[i];
      c[j]-=r[i];
      i++;
    }
    else
    {
      v[i][j]-=c[j];
      r[i]-=c[j];
      j++;
    }
  }
  if(s.back()=='D')v[i][j]=-r[i];
  else v[i][j]-=c[j];
  for(auto x:v)
  {
    for(long long y:x)
      cout<<y<<" ";
    cout<<'\n';
  }
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
