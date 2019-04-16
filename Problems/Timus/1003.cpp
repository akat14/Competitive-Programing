#include<bits/stdc++.h>
using namespace std;
const int MAXQ=3e5+1;
int f[2*MAXQ],t[2*MAXQ],le[2*MAXQ];
unordered_map<int,int>m;
void init(int q)
{
	for(int i=0;i<2*q;i++)
	{
		f[i]=i;
		t[i]=0;
		le[i]=0;
	}
	m.clear();
}
void dsu(int x)
{
	if(x==f[x])return;
	dsu(f[x]);
	t[x]^=t[f[x]];
	f[x]=f[f[x]];
}
void solve()
{
	int q,i,p=0;
	cin>>q;
	init(q);
	int l,r,tc,ans=q;
	string s;
	for(i=0;i<q;i++)
	{
		cin>>l>>r>>s;
		if(ans!=q)continue;
		tc=(s=="odd");
		if(m.find(l)==m.end())l=m[l]=p++;
		else l=m[l];
		if(m.find(r+1)==m.end())r=m[r+1]=p++;
		else r=m[r+1];
		dsu(l);
		dsu(r);
		if(f[l]==f[r] && (t[l]^t[r])!=tc)ans=i;
		if(f[l]!=f[r])
		{
			if(le[f[l]]<le[f[r]])swap(l,r);
			t[f[r]]=t[l]^t[r]^tc;
			f[f[r]]=f[l];
			if(le[f[l]]==le[f[r]])le[f[l]]++;
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	while(n!=-1)
	{
		solve();
		cin>>n;
	}
}
