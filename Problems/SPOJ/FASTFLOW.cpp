 #include<bits/stdc++.h>
using namespace std;
const int FLOWMAXN=5e5+4;
const int FLOWMAXM=3e5+4;
const long long FLOWINF=FLOWMAXM*1e9+4;
template<class T>
struct MAXFLOW 
{
	int to[FLOWMAXM*2];
	T cap[FLOWMAXM*2];
	int prev[FLOWMAXM*2];
	int clast[FLOWMAXN];
	int last[FLOWMAXN];
	int level[FLOWMAXN];
	int p;
	void init()
	{
		p=0;
		memset(to,0,sizeof(to));
		memset(cap,0,sizeof(cap));
		memset(prev,0,sizeof(prev));
		memset(clast,-1,sizeof(clast));
		memset(last,-1,sizeof(last));
	}
	MAXFLOW()
	{
		init();
	}
	void add_edge(int a,int b,int c)
	{
		to[p]=b;
		cap[p]=c;
		prev[p]=last[a];
		last[a]=clast[a]=p++;
	}
	int s,t;
	queue<int>q;
	bool bfs()
	{
		int i,x;
		memset(level,0,sizeof(level));
		level[t]=1;
		q.push(t);
		while(q.size())
		{
			x=q.front();
			q.pop();
			for(i=clast[x];i>-1;i=prev[i])
				if(!level[to[i]] && cap[i^1])
				{
					level[to[i]]=level[x]+1;
					q.push(to[i]);
				}
		}
		return level[s]!=0;
	}
	T dfs(int x,T cflow)
	{
		if(x==t)return cflow;
		int i;
		T flow;
		for(i=clast[x];i>-1;i=clast[x]=prev[i])
		{
			if(cap[i] && level[x]==level[to[i]]+1)
			{
				flow=dfs(to[i],min(cflow,cap[i]));
				if(flow)
				{
					cap[i]-=flow;
					cap[i^1]+=flow;
					return flow;
				}
			}
		}
		return 0;
	}
	T maxflow(int ss,int tt)
	{
		s=ss;
		t=tt;
		T ans=0,cans;
		while(bfs())
		{
			while((cans=dfs(s,FLOWINF)))
				ans+=cans;
			memcpy(clast,last,p*sizeof(int));
		}
		return ans;
	}
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,i,a,b,c;
	MAXFLOW<long long>MAX;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		MAX.add_edge(a,b,c);
		MAX.add_edge(b,a,c);
	}
	cout<<MAX.maxflow(1,n)<<'\n';
}
