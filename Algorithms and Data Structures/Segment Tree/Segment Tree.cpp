//Segment Tree
//!!! UPDATES ONLY LEAVES
//modify only conquer
template<class T>
struct SegmentTree
{
	int n;
	vector<T>it;
	SegmentTree(int nn)
	{
		n=nn;
		it.resize(4*n);
	}
	T conquer(const T &x,const T y)
	{
	}
	void up(int x,int l,int r,const int &I,const int &U)
	{
		if(l==r)
		{
			it[x]=U;
			return;
		}
		if(I>(l+r)/2)up(x*2+1,(l+r)/2+1,r,I,U);
		else up(x*2,l,(l+r)/2,I,U);
		it[x]=conquer(it[x*2],it[x*2+1]);
	}
	void update(int i,int u)
	{
		up(1,0,n-1,i,u);
	}
	T get(int x,int l,int r,const int &L,const int &R)
	{
		if(L<=l && r<=R)return it[x];
		int f=0;
		T ansl,ansr;
		if(L<=(l+r)/2)
		{
			f|=1;
			ansl=get(x*2,l,(l+r)/2,L,R);
		}
		if(R>(l+r)/2)
		{
			f|=2;
			ansr=get(x*2+1,(l+r)/2+1,r,L,R);
		}
		if(f==1)return ansl;
		if(f==2)return ansr;
		return conquer(ansl,ansr);
	}
	T query(int l,int r)
	{
		return get(1,0,n-1,l,r);
	}
};
