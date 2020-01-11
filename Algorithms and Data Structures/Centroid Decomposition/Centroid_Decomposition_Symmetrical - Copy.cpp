vector<vector<int>>adj(N);
int sz[N],curtime;
bool used[N];
void subtrees(int x,int p)
{
	sz[x]=1;
	for(auto y:adj[x])
	{
		if(!used[y] && y!=p)
		{
			subtrees(y,x);
			sz[x]+=sz[y];
		}
	}
}
int find_centroid(int x,int p,const int &n)
{
	for(auto y:adj[x])
		if(!used[y] && y!=p && sz[y]>n/2)return y;
	return x;
}
void insert(int x,int l)
{
	/*
	 * do stuff
	 * */
}
void erase(int x,int l)
{
	/*
	 * do stuff
	 * */
}
modul ans;
void combine(int x,int l)
{
	/*
	 * do stuff
	 * */
}
void dfs(int x,int p,int l,int t)
{
	if(t==0)insert(x,l);
	else if(t==1)erase(x,l);
	else combine(x,l);
	for(auto y:adj[x])
		if(!used[y] && y!=p)dfs(y,x,l+1,t);
}
void centroid_decomposition(int x)
{
	subtrees(x,x);
	int centroid=find_centroid(x,x,sz[x]);
	used[centroid]=1;
	for(auto y:adj[centroid])
		if(!used[y])centroid_decomposition(y);
	used[centroid]=0;
	insert(centroid,0);
	for(int y:adj[centroid])
	{
		if(!used[y])
		{
			dfs(y,centroid,1,2);
			dfs(y,centroid,1,0);
		}
	}
	curtime++;
}
