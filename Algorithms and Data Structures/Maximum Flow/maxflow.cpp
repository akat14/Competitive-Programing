template<class T>
struct MaxFlow 
{
	vector<T>cap;
	vector<int>to,prev,clast,last,level;
	int s,t;
	T INF;
	MaxFlow(int ss,int tt,int n)
	{
		s = ss;
		t = tt;
		INF = 0;
		clast = last = level = vector<int>(n+1,-1);
	}
	void add_edge(int a,int b,T c)
	{
		to.emplace_back(b);
		cap.emplace_back(c);
		prev.emplace_back(last[a]);
		clast[a] = last[a] = to.size() - 1;
		INF = max(INF, c);
	}
	bool bfs()
	{
		static int cnt = 0;
		cnt++;
		int i,x;
		fill(level.begin(), level.end(), 0);
		level[t]=1;
		queue<int>q;
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
	T maxflow()
	{
		T ans=0,cans;
		while(bfs())
		{
			while((cans=dfs(s,INF)))
				ans+=cans;
			clast = last;
		}
		return ans;
	}
	vector<int> min_vertex_cover()
	{
		vector<int>type(last.size(),2);
		int i, x;
		queue<int>q;
		for(i = last[s]; i > -1; i = prev[i])
		{
			type[to[i]] = 0;
			if(cap[i] == 0) type[to[i]] = 3;
			else q.push(to[i]);
		}
		type[s] = type[t] = 0;
		while(q.size())
		{
			x = q.front();
			q.pop();
			for(i = last[x]; i > -1; i = prev[i])
				if(type[to[i]] > 1)
				{
					if(type[to[i]] == 2)
					{
						type[to[i]] = 1;
						q.push(to[i]);
					}
					else if(cap[i] == 1)
					{
						type[to[i]] = 0;
						q.push(to[i]);
					}
				}
		}
		vector<int>ans;
		for( i = 0; i < (int)last.size(); i++)
			if(type[i] % 2 == 1) ans.emplace_back(i);
		return ans;
	}
};