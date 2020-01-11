#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1,LGN=20;
vector<int>adj[N];
int sz[N],used[N],father[N],szt;
int szdfs(int x,int p)
{
   	sz[x]=1;
  	for(int y:adj[x])
   		if(!used[y] && y!=p)
   			sz[x]+=szdfs(y,x);
 	return sz[x];
}
int cen(int x,int p)
{
   	for(int y:adj[x])
   		if(!used[y] && y!=p && sz[y]>szt/2)
   			return cen(y,x);
  	return x;
}
int centroid_decomposition(int x)
{
   	szt=szdfs(x,x);
   	int centroid=cen(x,x);
   	used[centroid]=1;
   	for(int y:adj[centroid])
   		if(!used[y])
   		{
   			int z=centroid_decomposition(y);
   			father[z]=centroid;
   		}
   	return centroid;
}