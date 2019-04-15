#include<bits/stdc++.h>
using namespace std;
const int MAXN=11e5+1;
int it[MAXN],n;
char big[MAXN];
int get(int u)
{
	int l=0,r=n,p;
	while(l+1!=r)
	{
		p=(1<<big[r-l])+l;
		if(u+it[p]>p)
		{
			u+=it[p];
			l=p;
		}
		else r=p;
	}
	return l+1;
}
void up(int x)
{
	while(x<MAXN)
	{
		it[x]++;
		x+=x&(-x);
	}
}
int down(int x)
{
	int s=0;
	while(x)
	{
		s+=it[x];
		x-=x&(-x);
	}
	return s;
}
int insum(int l,int r)
{
	return r-l+1-down(r)+down(l-1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k,i,ck,c,s,l;
	cin>>n>>k;
	for(i=2;i<=n;i++)
	{
		big[i]=big[i-1];
		if((1<<(big[i]+1))<i)big[i]++;
	}
	c=0;
	int ans=0;
	for(i=n;i>0;i--)
	{
		ck=k%i;
		if(!ck)ck=i;
		if(ck==n)s=0;
		else s=insum(c+1,n);
		if(s<ck)
		{
			ck-=s;
			c=0;
		}
		if(!c)l=0;
		else l=insum(1,c);
		c=get(l+ck);
		up(c);
		ans^=abs((n-i+1)-c);
	}
	cout<<ans<<'\n';
}
