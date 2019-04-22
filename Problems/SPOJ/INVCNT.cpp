#include<bits/stdc++.h>
using namespace std;
const int MAXBITSIZE=1e7+1;
struct Node
{
	long long su;
	Node()
	{
		su=0;
	}
};
struct BIT
{
	Node it[MAXBITSIZE];
	void init()
	{
		Node a;
		for(int i=0;i<MAXBITSIZE;i++)
			it[i]=a;
	}
	void con(Node &x,Node &y)
	{
		x.su+=y.su;
	}
	void update(int x,Node &u)
	{
		while(x<MAXBITSIZE)
		{
			con(it[x],u);
			x+=x&(-x);
		}
	}
	Node query(int x)
	{
		Node ans;
		while(x)
		{
			con(ans,it[x]);
			x-=x&(-x);
		}
		return ans;
	}
}T;
void solve()
{
	int n,i,a;
	long long ans=0;
	Node u;
	u.su=1;
	T.init();
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		ans+=T.query(MAXBITSIZE-a-1).su;
		T.update(MAXBITSIZE-a,u);
	}
	cout<<ans<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
		solve();
}
