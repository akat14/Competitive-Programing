#include<bits/stdc++.h>
using namespace std;
const int N=1000;// number of elements
struct segment_tree
{
	int tree[N*4][N*4];
	void mergeSE(int x,int y,int l,int r,int I)
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
	void setEl(int x,int y,int l,int r,int l2,int r2,int I,int J,int u)// set a value to a leaf
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
	int RMQ(int x,int y,int l,int r,int l2,int r2,int L,int R,int L2,int R2)// find the smalles element in the interval [l,r]
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
const int MAXN=501;
struct hill
{
	int height;
	int i;
	int j;
	int cans;
}a[MAXN*MAXN];
bool cmp(hill x,hill y)
{
	return x.height<y.height;
}
int MAXNEL;
segment_tree rmq;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,d,i,j;
	cin>>n>>m>>d;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cin>>a[i*m+j].height;
			a[i*m+j].i=i+m-j-1;
			a[i*m+j].j=i+j;
		}
	MAXNEL=n+m;
	sort(a,a+n*m,cmp);
	int ans=0;
	for(i=0;i<n*m;i++)
	{
		if(a[i-1].height!=a[i].height)
			for(j=i-1;j>=0 && a[j].height==a[i-1].height;j--)
				rmq.setEl(1,1,0,MAXNEL,0,MAXNEL,a[j].i,a[j].j,-a[j].cans);
		a[i].cans=-rmq.RMQ(1,1,0,MAXNEL,0,MAXNEL,max(a[i].i-d,0),min(a[i].i+d,MAXNEL),
					max(a[i].j-d,0),min(a[i].j+d,MAXNEL))+1;
		ans=max(ans,a[i].cans);
	}
	cout<<ans<<'\n';
}
