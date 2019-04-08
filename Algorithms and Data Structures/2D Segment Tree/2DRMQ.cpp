//Range Minimum Query
//setEl - log^2(N)
//RMQ - log(N)
const int N=;// number of elements
struct segment_tree
{
	int tree[N*4][N*4];
	void mergeSE(int x,int y,int l,int r,int I)//updates tree[x]
	{
		if(l==r)
		{
			tree[x][y]=min(tree[x*2][y],tree[x*2+1][y]);
			return;
		}
		if(I<=(l+r)>>1)this->mergeSE(x,y*2,l,(l+r)>>1,I);
		else this->mergeSE(x,y*2+1,(l+r)/2+1,r,I);
		tree[x][y]=min(tree[x*2][y],tree[x*2+1][y]);
	}
	void setEl(int x,int y,int l,int r,int l2,int r2,int I,int J,int u)// set a value to an element
	{
		if(l==r)
		{
			if(l2==r2)
			{
				tree[x][y]=u;
				return;
			}
			if(J<=(l2+r2)>>1)this->setEl(x,y*2,l,r,l2,(l2+r2)>>1,I,J,u);
			else this->setEl(x,y*2+1,l,r,(l2+r2)/2+1,r2,I,J,u);
			tree[x][y]=min(tree[x][y*2],tree[x][y*2+1]);
			return;
		}
		if(I<=(l+r)>>1)this->setEl(x*2,y,l,(l+r)>>1,l2,r2,I,J,u);
		else this->setEl(x*2+1,y,(l+r)/2+1,r,l2,r2,I,J,u);
		this->mergeSE(x,1,l2,r2,J);
	}
	int RMQ(int x,int y,int l,int r,int l2,int r2,int L,int R,int L2,int R2)// find the smalles element in the interval
	{
		int f=0,ansl,ansr;
		if(L<=l && r<=R)
		{
			if(L2<=l2 && r2<=R2)return tree[x][y];
			if(L2<=(l2+r2)>>1)
			{
				ansl=this->RMQ(x,y*2,l,r,l2,(l2+r2)>>1,L,R,L2,R2);
				f|=1;
			}
			if(ansl<=tree[x][y*2+1] && f==1)return ansl;
			if((l2+r2)>>1<R2)
			{
				ansr=this->RMQ(x,y*2+1,l,r,(l2+r2)/2+1,r2,L,R,L2,R2);
				f|=2;
			}
			if(f==1)return ansl;
			if(f==2)return ansr;
			return min(ansl,ansr);
		}
		if(L<=(l+r)>>1)
		{
			ansl=this->RMQ(x*2,y,l,(l+r)>>1,l2,r2,L,R,L2,R2);
			f|=1;
		}
		if(ansl<=tree[x*2+1][y] && f==1)return ansl;
		if((l+r)>>1<R)
		{
			ansr=this->RMQ(x*2+1,y,(l+r)/2+1,r,l2,r2,L,R,L2,R2);
			f|=2;
		}
		if(f==1)return ansl;
		if(f==2)return ansr;
		return min(ansl,ansr);
	}
};
