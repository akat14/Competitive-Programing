#include<bits/stdc++.h>
using namespace std;
struct Treap
{
	struct Node
	{
		long long key;
		long long pr;
		long long sz;
		long long v;
		long long sum;
		Node *l;
		Node *r;
		Node(long long kkey,long long vv)
		{
			key=kkey;
			pr=rand();
			l=r=NULL;
			sz=1;
			v=sum=vv;
		}
		void con()
		{
			sz=1;
			sum=v;
			if(l)
			{
				sz+=l->sz;
				sum+=l->sum;
			}
			if(r)
			{
				sz+=r->sz;
				sum+=r->sum;
			}
		}
		void output()
		{
			if(l)l->output();
			cout<<key<<endl;
			if(r)r->output();
		}
	};
	Node *node;
	Treap()
	{
		node=NULL;
	}
	void split(Node *T,Node *&L,Node *&R,long long key)
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
	void split_sz(Node *T,Node *&L,Node *&R,long long x)
	{
		if(!T)
		{
			L=R=NULL;
			return;
		}
		int size=1;
		if(T->l)size+=T->l->sz;
		if(size <= x)
		{
			L=T;
			split_sz(T->r,L->r,R,x-size);
		}
		else
		{
			R=T;
			split_sz(T->l,L,R->l,x);
		}
		T->con();
	}
	void merge(Node *&T,Node *L,Node *R)
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
	void insert(long long key,long long v)
	{
		Node *L,*MID,*R;
		split(node,L,R,key);
		split(L,L,MID,key-1);
		if(MID)
		{
			MID->v=MID->sum=MID->v+v;
			MID->sz+=1;
		}
		else MID=new Node(key,v);
		merge(L,L,MID);
		merge(node,L,R);
	}
	void erase(long long x)
	{
		Node *L,*MID,*R;
		split(node,L,R,x);
		split(L,L,MID,x-1);
		merge(node,L,R);
	}
	int query(long long x)
	{
		Node *L,*R;
		split(node,L,R,x);
		long long ans=L->sum;
		merge(node,L,R);
		return ans;
	}
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long q,i,a,b,l=0;
	cin>>q;
	Treap T;
	for(i=0;i<q;i++)
	{
		cin>>a>>b;
		a^=l;
		b^=l;
		T.insert(a,b);
		l=T.query(a);
		cout<<a<<' '<<l<<'\n';
	}
}
