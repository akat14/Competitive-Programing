#include<bits/stdc++.h>
using namespace std;
vector<int>father;
int find(int x)
{
  if(x==father[x])return x;
  return father[x]=find(father[x]);
}
int main()
{
  int n,h,i,j;
  cin>>h>>n;
  father=vector<int>(n+2);
  vector<int>level(n+2,1);
  vector<pair<int,int>>points(n);
  vector<pair<int,pair<int,int>>>edges;
  edges.push_back({h*h,{0,1}});
  father[0]=0;
  father[1]=1;
  for(i=0;i<n;i++)
  {
      father[i+2]=i+2;
      cin>>points[i].first>>points[i].second;
      edges.push_back({points[i].second*points[i].second,{0,i+2}});
      edges.push_back({(h-points[i].second)*(h-points[i].second),{1,i+2}});
      for(j=0;j<i;j++)
        edges.push_back({(points[i].first-points[j].first)*(points[i].first-points[j].first)+
                          (points[i].second-points[j].second)*(points[i].second-points[j].second),{i+2,j+2}});
  }
  sort(edges.begin(),edges.end());
  for(auto edge:edges)
  {
    auto x=edge.second;
    int y=edge.first;
    x.first=find(x.first);
    x.second=find(x.second);
    if(x.first==x.second)continue;
    if(level[x.second]>level[x.first])swap(x.first,x.second);
    if(level[x.first]==x.second)level[x.first]++;
    father[x.second]=x.first;
    if(find(0)==find(1))
    {
      printf("%.4lf\n",sqrt(y));
      return 0;
    }
  }
}
