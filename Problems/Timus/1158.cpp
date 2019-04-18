#include<iostream>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
const int N=51,M=51,P=11,PLEN=11,ANSLEN=180;
int son[N*PLEN][M],fail[N*PLEN];
struct BigSum
{
	int a[ANSLEN];
	BigSum()
	{
		memset(a,0,sizeof(a));
	}
	BigSum operator=(BigSum x)
	{
		int i;
		for(i=0;i<ANSLEN;i++)
			a[i]=x.a[i];
		return *this;
	}
	BigSum operator+(BigSum x)
	{
		BigSum y;
		int i,o=0;
		for(i=0;i<ANSLEN;i++)
		{
			y.a[i]=a[i]+x.a[i]+o;
			o=y.a[i]/10;
			y.a[i]=y.a[i]%10;
		}
		return y;
	}
	void print()
	{
		int i;
		bool l=0;
		for(i=ANSLEN-1;i>=0;i--)
		{
			if(a[i] || i==0)l=1;
			if(l)cout<<a[i];
		}
		cout<<'\n';
	}
}dp[2][N*PLEN];
bool suc[N*PLEN];
map<char,int>ma;
int main()
{
	int n,m,p,i,j,k,st,cnt=1,x;
	cin>>n>>m>>p;
	char c[51];
	for(i=0;i<n;i++)
	{
		cin>>c[i];
		ma[c[i]]=i;
	}
	string s;
	for(i=0;i<p;i++)
	{
		cin>>s;
		st=0;
		for(j=0;j<(int)s.size();j++)
		{
			if(son[st][ma[s[j]]]!=0)st=son[st][ma[s[j]]];
			else st=son[st][ma[s[j]]]=cnt++;
		}
		suc[st]=1;
	}
	queue<int>q;
	q.push(0);
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(i=0;i<n;i++)
		{
			if(son[x][i]!=0)
			{
				if(x!=0)
				{
					st=fail[x];
					while(st!=0)
					{
						if(son[st][i]!=0)break;
						st=fail[st];
					}
					fail[son[x][i]]=son[st][i];
					suc[son[x][i]]|=suc[son[st][i]];
				}
				q.push(son[x][i]);
			}
		}
	}
	dp[1][0].a[0]=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<cnt;j++)
			memset(dp[i&1][j].a,0,sizeof(dp[i&1][j].a));
		for(j=0;j<cnt;j++)
		{
			for(k=0;k<n;k++)
			{
				st=j;
				while(st!=0)
				{
					if(son[st][k]!=0)break;
					st=fail[st];
				}
				st=son[st][k];
				if(suc[st]^1)dp[i&1][st]=dp[i&1][st]+dp[(i&1)^1][j];
			}
		}
	}
	BigSum ans;
	for(j=0;j<cnt;j++)
		ans=ans+dp[(i&1)^1][j];
	ans.print();
}