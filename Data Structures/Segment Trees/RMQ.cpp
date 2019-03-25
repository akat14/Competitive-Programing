//Range Minimum Query
//setAr() - N
//setEl - log(N)
//RMQ - log(N)
const int N=;// number of elements
struct segment_tree
{
	int tree[N*4];
	void setAr(int x,int l,int r,int *u)// set values to all leaves
	{
		if(l==r)
		{
			tree[x]=u[l];
			return;
		}
		this->setAr(x*2,l,(l+r)>>1,u);
		this->setAr(x*2+1,(l+r)/2+1,r,u);
		tree[x]=min(tree[x*2],tree[x*2+1]);
	}
	void setEl(int x,int l,int r,int I,int u)// UNTESTED set a value to a leaf
	{
		if(l==r)
		{
			tree[x]=u;
			return;
		}
		if(I<=(l+r)>>1)this->setEl(x*2,l,(l+r)>>1,I,u);
		else this->setEl(x*2+1,(l+r)/2+1,r,I,u);
		tree[x]=min(tree[x*2],tree[x*2+1]);
	}
	int RMQ(int x,int l,int r,int L,int R)// find the smalles element in the interval [l,r]
	{
		if(L<=l && r<=R)return tree[x];
		int f=0,ansl,ansr;
		if(L<=(l+r)>>1)
		{
			ansl=this->RMQ(x*2,l,(l+r)>>1,L,R);
			f|=1;
		}
		if(ansl<=tree[x*2+1] && f==1)return ansl;
		if((l+r)>>1<R)
		{
			ansr=this->RMQ(x*2+1,(l+r)/2+1,r,L,R);
			f|=2;
		}
		if(f==1)return ansl;
		if(f==2)return ansr;
		return min(ansl,ansr);
	}
};