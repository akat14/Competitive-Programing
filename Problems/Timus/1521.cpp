#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
int it[4*MAXN],n;
int get(int u)
{
	int x=1,l=1,r=n;
	while(l!=r)
	{
		it[x]++;
		if(u+it[x*2]>(l+r)/2)
		{
			u+=it[x*2];
			x=x*2+1;
			l=(l+r)/2+1;
		}
		else
		{
			x*=2;
			r=(l+r)/2;
		}
	}
	it[x]++;
	return l;
}
int insum(int x,int l,int r,int L,int R)
{
	if(L<=l && r<=R)return r-l+1-it[x];
	int ans=0;
	if(L<=(l+r)/2)ans+=insum(x*2,l,(l+r)>>1,L,R);
	if(R>(l+r)/2)ans+=insum(x*2+1,(l+r)/2+1,r,L,R);
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k,i,ck,c,s,l;
	cin>>n>>k;
	c=0;
	for(i=n;i>0;i--)
	{
		ck=k%i;
		if(!ck)ck=i;
		if(ck==n)s=0;
		else s=insum(1,1,n,c+1,n);
		if(s<ck)
		{
			ck-=s;
			c=0;
		}
		if(!c)l=0;
		else l=insum(1,1,n,1,c);
		c=get(l+ck);
		cout<<c;
		if(i!=1)cout<<' ';
	}
	cout<<'\n';
}
