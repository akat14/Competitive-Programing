#include<bits/stdc++.h>
using namespace std;
struct mat
{
	int x[6][6];
	mat()
	{
		memset(x,0,sizeof(x));
	}
	mat operator*(mat a)
	{
		mat b;
		int n=6,i,j,k;
		for(i=0;i<n;i++)
			for(k=0;k<n;k++)
				for(j=0;j<n;j++)
					b.x[i][j]+=x[i][k]*a.x[k][j];
		return b;
	}
};
mat cur,ans;
void init()
{
	cur.x[0][0]=cur.x[0][1]=cur.x[1][2]=cur.x[2][4]=cur.x[3][5]=cur.x[4][4]=cur.x[4][5]=cur.x[5][2]=1;
	int i;
	for(i=0;i<6;i++)
		ans.x[i][i]=1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	init();
	cin>>n;
	if(n==1)
	{
		cout<<"1\n";
		return 0;
	}
	n-=2;
	for(;n;n>>=1)
	{
		if(n&1)ans=cur*ans;
		cur=cur*cur;
	}
	cout<<ans.x[0][2]+ans.x[0][4]+ans.x[4][2]+ans.x[4][4]+ans.x[5][2]+ans.x[5][4]<<'\n';
}
