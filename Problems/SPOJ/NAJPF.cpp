#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1;
int kmp[MAXN];
void build_kmp(string p)
{
	int i,j;
	for(i=1;i<=(int)p.size();i++)
	{
		j=kmp[i];
		while(p[j]!=p[i] && j!=0)
			j=kmp[j];
		if(p[j]==p[i])kmp[i+1]=j+1;
	}
}
vector<int>ans;
void find(string s,string p)
{
	int i,j=0;
	for(i=0;i<(int)s.size();i++)
	{
		while(s[i]!=p[j] && j!=0)
			j=kmp[j];
		j+=(s[i]==p[j]);
		if(j==(int)p.size())
		{
			ans.push_back(i-j+2);
			j=kmp[j];
		}
	}
}
void solve()
{
	memset(kmp,0,sizeof(kmp));
	ans.clear();
	string s,p;
	cin>>s>>p;
	build_kmp(p);
	find(s,p);
	int i;
	if(!ans.size())
	{
		cout<<"Not Found\n";
		return;
	}
	cout<<ans.size()<<'\n';
	for(i=0;i<(int)ans.size()-1;i++)
		cout<<ans[i]<<" ";
	cout<<ans[i]<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
		if(t)cout<<'\n';
	}
}
