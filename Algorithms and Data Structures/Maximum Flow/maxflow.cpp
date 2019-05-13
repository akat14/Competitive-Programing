#include<bits/stdc++.h>
using namespace std;
const int FLOWMAXN=;//maximum number of vertixes
const int FLOWMAXM=;//maximum numver of edges
const int FLOWINF=;//maximum value of the flow
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
