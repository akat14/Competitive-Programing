// Range Minumum Query
// SetAr N
// SetEl log(N)
// RMQ log(N)
onst int MAXEL=1<<30;// the maximum possible element in the problem
struct segment_tree
{
	int mi;
	segment_tree *left,*right;
	segment_tree()
	{
		mi=MAXEL;
	}
	void setAr(int l,int r,int *u)//set a values for all elements
	{
		if(l==r)
		{
			mi=u[l];
			return;
		}
		if(left==NULL)
		{
			left=new segment_tree;
			right=new segment_tree;
		}
		(*left).setAr(l,(l+r)>>1,u);
		(*right).setAr((l+r)/2+1,r,u);
		mi=min(left->mi,right->mi);
	}
	void setEl(int l,int r,int I,int u) //set the value of the element I
	{
		if(l==r)
		{
			mi=u;
			return;
		}
		if(left==NULL)
		{
			left=new segment_tree;
			right=new segment_tree;
		}
		if(I<=(l+r)>>1)(*left).setEl(l,(l+r)>>1,I,u);
		else (*right).setEl((l+r)/2+1,r,I,u);
		mi=min(left->mi,right->mi);
	}
	int RMQ(int l,int r,int L,int R)
	{
		if(L<=l && r<=R)return mi;
		if(left==NULL)
		{
			left=new segment_tree;
			right=new segment_tree;
		}
		int ans=MAXEL;
		if(L<=(l+r)>>1)ans=min(ans,(*left).RMQ(l,(l+r)>>1,L,R));
		if(ans==mi)return ans;
		if((l+r)>>1<R)ans=min(ans,(*right).RMQ((l+r)/2+1,r,L,R));
		return ans;
	}
};
