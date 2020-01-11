int spt[LGN][2*N],level[2*N],ver[2*N],id[N],lg[2*N];
void dfs(int x,int p,int l)
{
   	static int cnt=0;
   	level[cnt]=l;
   	ver[cnt]=x;
   	id[x]=cnt++;
   	for(int y:adj[x])
   		if(y!=p)
   		{
   			dfs(y,x,l+1);
   			level[cnt]=l;
   			ver[cnt++]=x;
 		}
}
void build_spt(int n)
{
   	int i,j;
   	lg[1]=0;
   	for(i=2;i<=2*n;i++)
   	{
   		lg[i]=lg[i-1];
   		if((i&(i-1))==0)lg[i]++;
   	}
   	for(i=0;i<2*n;i++)
   		spt[0][i]=i;
   	for(i=1;i<=lg[2*n];i++)
   		for(j=0;j+(1<<i)-1<2*n;j++)
   			if(level[spt[i-1][j]]<level[spt[i-1][j+(1<<(i-1))]])
   				spt[i][j]=spt[i-1][j];
  			else spt[i][j]=spt[i-1][j+(1<<(i-1))];
}
int lca(int x,int y)
{
   	if(id[x]>id[y])swap(x,y);
   	int d=id[y]-id[x]+1;
   	int l=spt[lg[d]][id[x]],r=spt[lg[d]][id[y]-(1<<lg[d])+1];
  	if(level[l]<level[r])return ver[l];
 	return ver[r];
}