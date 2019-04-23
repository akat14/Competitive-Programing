const int MSIZE=6;
struct mat
{
	int x[MSIZE][MSIZE];
	mat()
	{
		memset(x,0,sizeof(x));
	}
	zero()
	{
		int i,j;
		for(i=0;i<MSIZE;i++)
			for(j=0;j<MSIZE;j++)
				x[i][j]=(i==j);
	}
	mat operator*(mat a)
	{
		mat b;
		int i,j,k;
		for(i=0;i<MSIZE;i++)
			for(k=0;k<MSIZE;k++)
				for(j=0;j<MSIZE;j++)
					b.x[i][j]+=x[i][k]*a.x[k][j];
		return b;
	}
};
