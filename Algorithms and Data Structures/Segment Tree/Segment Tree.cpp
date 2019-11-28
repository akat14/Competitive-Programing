#include<bits/stdc++.h>
using namespace std;
template<class T,class P>
struct SegmentTree
{
	int n;
	vector<T>it;
	vector<bool>lazy;
	vector<P>u;
	SegmentTree(int nn)
	{
		n=nn;
		it.resize(4*n);
		lazy.resize(4*n);
		u.resize(4*n);
	}
	T combine(const T &l,const T &r)
	{
		T ans;
		/*
		 * do stuff here
		 * ans=;
		*/
		return ans;
	}
	void push(int x,int l,int r)
	{
		if(lazy[x]==0)return;
		if(x*2<4*n)
		{
			lazy[x*2]=lazy[x];
			lazy[x*2+1]=lazy[x];
			/*
			 * do stuff here
			 * u[x*2]=;
			 * u[x*2+1]=;
			 */
		}
		/*
		 * do stuff here
		 * it[x]=;
		*/
		lazy[x]=0;
	}
	void up(int x,int l,int r,const int &L,const int &R,const P &U)
	{
		push(x,l,r);
		if(L<=l && r<=R)
		{
			lazy[x]=1;
			u[x]=U;
			return;
		}
		if(L<=(l+r)/2)up(x*2,l,(l+r)/2,L,R,U);
		if(R>(l+r)/2)up(x*2+1,(l+r)/2+1,r,L,R,U);
		push(x*2,l,(l+r)/2);
		push(x*2+1,(l+r)/2+1,r);
		it[x]=combine(it[x*2],it[x*2+1]);
	}
	void update(int l,int r,P u)
	{
		up(1,0,n-1,l,r,u);
	}
	T qu(int x,int l,int r,int L,int R)
	{
		push(x,l,r);
		if(L<=l && r<=R)return it[x];
		T ansl,ansr;
		int f=0;
		if(L<=(l+r)/2)
		{
			f|=1;
			ansl=qu(x*2,l,(l+r)/2,L,R);
		}
		if(R>(l+r)/2)
		{
			f|=2;
			ansr=qu(x*2+1,(l+r)/2+1,r,L,R);
		}
		if(f==1)return ansl;
		if(f==2)return ansr;
		return combine(ansl,ansr);
	}
	T query(int l,int r)
	{
		return qu(1,0,n-1,l,r);
	}
};
