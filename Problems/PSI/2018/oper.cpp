#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>h;
vector<pair<int,int> >v;
bool cmp(pair<int,int>a,pair<int,int>b)
{
	if(a.first==b.first)return a.second<b.second;
	return a.first<b.first;
}
int main()
{
	int n,t,m,k,i,j,x,y,ci,cj;
	char c;
	cin>>n>>t>>m;
	while(t--)
	{
		cin>>i>>j;
		h[{i,j}]^=1;
	}
	x=0;
	y=2;
	while(m--)
	{
		cin>>t;
		if(t==1)
		{
			cin>>c;
			if(c=='R')
			{
				swap(x,y);
				y^=1;
			}
			if(c=='L')
			{
				swap(x,y);
				x^=1;
			}
			if(c=='Q')
			{
				x^=1;
				y^=1;
			}
			if(c=='V')x^=1;
			if(c=='H')y^=1;
		}
		else
		{
			cin>>i>>j;
			if(x==0)ci=i;
			if(x==1)ci=n+1-i;
			if(x==2)cj=i;
			if(x==3)cj=n+1-i;
			if(y==0)ci=j;
			if(y==1)ci=n+1-j;
			if(y==2)cj=j;
			if(y==3)cj=n+1-j;
			h[{ci,cj}]^=1;
		}
	}
	for(auto it=h.begin();it!=h.end();it++)
	{
		if(it->second==1)
		{
			i=it->first.first;
			j=it->first.second;
			if(x==0)ci=i;
			if(x==1)ci=n+1-i;
			if(x==2)ci=j;
			if(x==3)ci=n+1-j;
			if(y==0)cj=i;
			if(y==1)cj=n+1-i;
			if(y==2)cj=j;
			if(y==3)cj=n+1-j;
			v.push_back({ci,cj});
		}
	}
	sort(v.begin(),v.end(),cmp);
	cin>>k;
	for(i=0;i<k;i++)
		cout<<v[i].first<<" "<<v[i].second<<'\n';
}
