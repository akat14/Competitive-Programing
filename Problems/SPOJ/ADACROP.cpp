#include<bits/stdc++.h>
using namespace std;
struct Treap
{
	struct Node
	{
		int key;
		int pr;
		int sz;
		int br;
		Node *l;
		Node *r;
		Node(int kkey)
		{
			key=kkey;
			pr=rand();
			l=r=NULL;
			sz=1;
			br=1;
		}
		void con()//Keeps everything updated during splits and merges
		{
			sz=br;
			if(l)
			{
				sz+=l->sz;
			}
			if(r)
			{
				sz+=r->sz;
			}
		}
	};
	Node *node;
	Treap()
	{
		node=NULL;
	}
	void split(Node *T,Node *&L,Node *&R,int key)//splits T into L and R where all the keys of L are <=key and all the keys of R are >key
	{
		if(!T)
		{
			L=R=NULL;
			return;
		}
		if(T->key <= key)
		{
			L=T;
			split(T->r,L->r,R,key);
		}
		else
		{
			R=T;
			split(T->l,L,R->l,key);
		}
		T->con();
	}
	void merge(Node *&T,Node *L,Node *R)//merges L and R into T where all keys of L are <= of all keys in R
	{
		if(!L)
		{
			T=R;
			return;
		}
		if(!R)
		{
			T=L;
			return;
		}
		if(L->pr > R->pr)
		{
			T=L;
			merge(T->r,L->r,R);
		}
		else
		{
			T=R;
			merge(T->l,L,R->l);
		}
		T->con();
	}
	void insert(int key)//inserts an element into the treap
	{
		Node *L,*MID,*R;
		split(node,L,R,key);
		split(L,L,MID,key-1);
		if(MID)
		{
			MID->br+=1;
			MID->sz+=1;
		}
		else MID=new Node(key);
		merge(L,L,MID);
		merge(node,L,R);
	}
	void erase(int x)//erases all elements = to x from the treap
	{
		Node *L,*MID,*R;
		split(node,L,R,x);
		split(L,L,MID,x-1);
		merge(node,L,R);
	}
	int query(int x)//answer the qurty how many numbers <=x are in the trap
	{
		Node *L,*R;
		split(node,L,R,x);
		int ans=0;
		if(L)ans=L->sz;
		merge(node,L,R);
		return ans;
	}
};
map<int,Treap>m;
const int N=2e5+1;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Treap T;
	int n,q,i,a,po[N];
	cin>>n>>q;
	for(i=0;i<n;i++)
	{
		cin>>po[i];
		m[po[i]].insert(i);
	}
	int b,c;
	for(i=0;i<q;i++)
	{
		cin>>a>>b;
		c=po[a];
		po[a]=b;
		m[c].erase(a);
		m[b].insert(a);
		cout<<m[b].query(a-1)<<'\n';
	}
}
