struct Treap
{
	struct Node
	{
		int key;
		int pr;
		int sz;
		Node *l;
		Node *r;
		Node(int kkey)
		{
			key=kkey;
			pr=rand();
			l=r=NULL;
			sz=1;
		}
		void con()
		{
			sz=1;
			if(l)
			{
				sz+=l->sz;
			}
			if(r)
			{
				sz+=r->sz;
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
	void split(Node *T,Node *&L,Node *&R,int key)
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
	void split_sz(Node *T,Node *&L,Node *&R,int x)
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
	void insert(int key)
	{
		Node *L,*MID,*R;
		split(node,L,R,key);
		split(L,L,MID,key-1);
		if(MID)
		{
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
		int ans=L->sz;
		merge(node,L,R);
		return ans;
	}
};
