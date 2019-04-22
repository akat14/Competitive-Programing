#include<bits/stdc++.h>
using namespace std;
const int MAXBITSIZE=/*Set size*/;
struct Node
{
	//Do stuff here
	Node()
	{
		//Do stuff here
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
		//Do stuff here
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
