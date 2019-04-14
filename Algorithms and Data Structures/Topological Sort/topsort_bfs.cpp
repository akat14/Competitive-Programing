#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+1;
vector<int>v[MAXN];
int p,ans[MAXN],br[MAXN];
queue<int>q;
int main()
{
	int n,m,i,x,y;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		br[y]++;
	}
	for(i=1;i<=n;i++)
		if(!br[i])q.push(i);
	while(q.size())
	{
		x=q.front();
		q.pop();
		ans[p++]=x;
		for(i=0;i<(int)v[x].size();i++)
		{
			br[v[x][i]]--;
			if(!br[v[x][i]])q.push(v[x][i]);
		}
	}
	if(p!=n)cout<<"Impossible.\n";
	else
	{
		for(i=0;i<n-1;i++)
			cout<<ans[i]<<" ";
		cout<<ans[i]<<'\n';
	}
}
