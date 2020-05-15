#include<bits/stdc++.h>
using namespace std;
map<char,int>m;
pair<int,char>fu(int x)
{
	if(x==3)return {1,'0'};
	if(x==2)return {1,'-'};
	if(x==1)return {0,'+'};
	if(x==0)return {0,'0'};
	if(x==-1)return {0,'-'};
	if(x==-2)return {-1,'+'};
	if(x==-3)return {-1,'0'};
	return {0,'0'};
}
void solve()
{
	string s,s2,a1="",a2="";
	cin>>s>>s2;
	int c1,c2,l1=0,l2=0,i;
	while(s.size()<s2.size())
		s="0"+s;
	while(s2.size()<s.size())
		s2="0"+s2;
	s="0"+s;
	s2="0"+s2;
	for(i=s.size()-1;i>=0;i--)
	{
		c1=l1+m[s[i]]+m[s2[i]];
		c2=l2+m[s[i]]-m[s2[i]];
		auto x=fu(c1);
		l1=x.first;
		a1=x.second+a1;
		x=fu(c2);
		l2=x.first;
		a2=x.second+a2;
	}
	int f=0;
	for(i=0;i<(int)a1.size();i++)
	{
		if(a1[i]!='0')f=1;
		if(f || i+1==(int)a1.size())cout<<a1[i];
	}
	cout<<'\n';
	f=0;
	for(i=0;i<(int)a2.size();i++)
	{
		if(a2[i]!='0')f=1;
		if(f || i+1==(int)a2.size())cout<<a2[i];
	}
	cout<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	m['-']=-1;
	m['0']=0;
	m['+']=1;
	while(t--)
		solve();
}
