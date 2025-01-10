#include<bits/stdc++.h>
using namespace std;
const long long W=301,INF=1e9;
vector<long long>v[W];
deque<long long>d;
vector<long long>sum;
vector<long long>knapsack;
long long get(long long i,int m)
{
  if(m==0)return knapsack[i];
  return knapsack[i]+sum[m-1];
}
long long better(int i,int j,int w)
{
  long long p=(j-i)/w;
  long long l=1;
  long long r=v[w].size()-(j-i)/w;
  long long m,f=1;
  while(l<=r)
  {
      m=(l+r)>>1;
      if(get(i,m+p)>=get(j,m))l=m+1;
      else r=m-1,f=0;
  }
  if(f)return INF;
  return (l-1+p)*w+i;
}
void add(long long i,int w)
{
  if(!d.size())
  {
    d.push_back(i);
    return;
  }
  while(d.size() && better(i,d[0],w)==INF)
    d.pop_front();
  while(d.size()>1 && better(i,d[0],w)>=better(d[0],d[1],w))
    d.pop_front();
  d.push_front(i);
}
long long find(long long x,long long r,long long i)
{
  return get(x,(r-x)/i);
}
int main()
{
  long long n,k,i,w,p,j,l,r,cnt;
  cin>>n>>k;
  for(i=0;i<n;i++)
  {
      cin>>w>>p;
      v[w].push_back(p);
  }
  sum=vector<long long>(n+1);
  knapsack=vector<long long>(k+1);
  for(i=1;i<W;i++)
  {
      if(i>k)break;
      if(!v[i].size())continue;
      sort(v[i].begin(),v[i].end());
      reverse(v[i].begin(),v[i].end());
      sum[0]=v[i][0];
      for(j=1;j<v[i].size();j++)
        sum[j]=sum[j-1]+v[i][j];
      for(j=0;j<i;j++)
      {
        cnt=0;
        for(l=k-j;l>=0 && cnt<v[i].size();l-=i,cnt++)
          add(l,i);
        for(r=k-j;r>=i;r-=i)
        {
          if(l>=0)add(l,i);
          while((d.size() && d.back()==r) || (d.size()>1 && find(d.back(),r,i)<=find(d[d.size()-2],r,i)))
            d.pop_back();
          l-=i;
          long long x=d.back();
          long long y=(r-x)/i;
          knapsack[r]=max(knapsack[r],find(d.back(),r,i));
        }
        while(d.size())
          d.pop_back();
      }
  }
  for(i=1;i<k;i++)
    cout<<knapsack[i]<<' ';
  cout<<knapsack[i]<<'\n';
}
