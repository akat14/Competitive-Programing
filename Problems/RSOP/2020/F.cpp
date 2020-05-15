#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
map<string,int>m;
int level[N*2],father[N*2];
int cnt;
int get(string &x)
{
	auto it=m.find(x);
	if(it==m.end())
	{
		m[x]=cnt;
		father[cnt]=cnt;
		level[cnt]=1;
		return cnt++;
	}
	return it->second;
}
int root(int &x)
{
	if(x==father[x])return x;
	return x=root(father[x]);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,br,a,b,i;
	string s,s2;
	while(cin>>n)
	{
		if(n==0)break;
		cnt=br=0;
		m.clear();
		for(i=0;i<n;i++)
		{
			cin>>s>>s2;
			a=get(s);
			b=get(s2);
			root(a);
			root(b);
			if(a!=b)
			{
				br++;
				if(level[a]>=level[b])
				{
					father[b]=a;
					if(level[a]==level[b])level[a]++;
				}
				else father[a]=b;
			}
		}
		cout<<cnt-br-1<<'\n';
	}
}
