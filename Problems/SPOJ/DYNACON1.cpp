#include<bits/stdc++.h>
using namespace std;
struct Node
{
	pair<int,int>key;
	int pr;
	int sz;
	int br;
	Node *l;
	Node *r;
	Node *father;
	Node(pair<int,int>k)
	{
		key=k;
		pr=rand();
		l=r=father=NULL;
		sz=1;
		br=1;
	}
	void con()//Keeps everything updated during splits and merges
	{
		father = NULL;
		sz=br;
		if(l)
		{
			sz+=l->sz;
			l->father = this;
		}
		if(r)
		{
			sz+=r->sz;
			r->father = this;
		}
	}
	void output()//Outputs the keys in the treap in ascending order
	{
		if(l)l->output();
		cout<<key.first<<" "<<key.second<<endl;
		if(r)r->output();
	}
	int find_sz()
	{
		if(!father) return 0;
		int ans = 0;
		if(father->r && father->r == this) ans += father->sz - sz;
		return ans + father->find_sz();
	}
	Node* find_highest()//root of the Treap not of the tree
	{
		if(!father) return this;
		return father->find_highest();
	}
	int find_root()
	{
		Node *x;
		x = this->find_highest();
		while(x->l)
			x = x->l;
		return x->key.first;
	}
};
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
struct List
{
	List *next,*prev;
	Node *key;
	List(Node *k)
	{
		key = k;
		next = NULL;
		prev = NULL;
	}
	~List()
	{
		if(prev) prev->next = next;
		if(next) next->prev = prev;
	}
};
struct DynamicConnectivityForrest
{
	map<pair<int,int>,pair<List*,List*>>m;
	vector<Node*>T;
	vector<List*>l,r;
	DynamicConnectivityForrest(int n)
	{
		T.resize(n);
		l.resize(n);
		r.resize(n);
		for(int i = 0; i < n; i++)
		{
			T[i] = NULL;
			l[i] = NULL;
			r[i] = NULL;
		}
	}
	void reroot(int u)
	{
		int root = u;
		if(l[u]) root = l[u]->key->find_root();
		if(root == u) return;
		int sz = l[u]->key->find_sz();
		if(l[u]->key->l) sz += l[u]->key->l->sz;
		Node *L,*R;
		split_sz(T[root], L, R, sz);
		merge(T[u], R, L);
		T[root] = NULL;
	}
	void add_edge(int u,int v)
	{
		int root = u;
		Node *L, *R;
		L = R = NULL;
		if(l[u])
		{
			root = l[u]->key->find_root();
			int sz = r[u]->key->find_sz();
			if(r[u]->key->l) sz += r[u]->key->l->sz;
			split_sz(T[root], L, R, sz+1);
		}
		reroot(v);
		Node *X,*Y;
		X = new Node({u,v});
		Y = new Node({v,u});
		List *p,*p2;
		p = new List(X);
		p2 = new List(X);
		if(l[u])
		{
			p->next = l[u];
			l[u]->prev = p;
		}
		l[u] = p;
		if(r[v])
		{
			p2->next = r[v];
			r[v]->prev = p2;
		}
		r[v] = p2;
		m[{u,v}] = {p,p2};
		p = new List(Y);
		p2 = new List(Y);
		if(l[v])
		{
			p->next = l[v];
			l[v]->prev = p;
		}
		l[v] = p;
		if(r[u])
		{
			p2->next = r[u];
			r[u]->prev = p2;
		}
		r[u] = p2;
		m[{v,u}] = {p,p2};
		merge(T[root], L, X);
		merge(L, T[v], Y);
		merge(L, L, R);
		merge(T[root], T[root], L);
		T[v] = NULL;
	}
	void remove_edge(int u,int v)
	{
		Node *L, *MID,*R, *X;
		int root = l[u]->key->find_root();
		auto x = m[{u,v}];
		x.second = m[{v,u}].second;
		int sz = x.first->key->find_sz();
		int sz2 = x.second->key->find_sz();
		if(x.first->key->l) sz += x.first->key->l->sz;
		if(x.second->key->l) sz2 += x.second->key->l->sz;
		if(sz > sz2) swap(sz, sz2);
		sz2 -= sz + 1;
		split_sz(T[root], L, R, sz);
		split_sz(R, X, R, 1);
		delete X;
		sz = x.second->key->find_sz();
		split_sz(R, MID, R, sz2);
		split_sz(R, X, R, 1);
		delete X;
		T[root] = NULL;
		merge(L, L, R);
		if(L)
		{
			root = L->find_root();
			T[root] = L;
		}
		if(MID)
		{
			root = MID->find_root();
			T[root] = MID;
		}
		x = m[{u, v}];
		if(l[u] == x.first) l[u] = l[u]->next;
		delete x.first;
		if(r[v] == x.second) r[v] = r[v]->next;
		delete x.second;
		x = m[{v, u}];
		if(l[v] == x.first) l[v] = l[v]->next;
		delete x.first;
		if(r[u] == x.second) r[u] = r[u]->next;
		delete x.second;
		m.erase({u,v});
		m.erase({v,u});
	}
	bool is_connected(int u,int v)
	{
		int rootu = u;
		if(l[u]) rootu = l[u]->key->find_root();
		int rootv = v;
		if(l[v]) rootv = l[v]->key->find_root();
		//cout<<  rootu <<" "<< rootv <<endl;
		return rootu == rootv;
	}
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,i,a,b,q;
	string s;
	cin>>n>>q;
	DynamicConnectivityForrest F(n);
	for(i = 0; i < q; i++)
	{
		cin>>s>>a>>b;
		a--;
		b--;
		if(a == b)continue;
		if(s[0] == 'c')
		{
			if(F.is_connected(a,b)) cout<<"YES\n";
			else cout<<"NO\n";
		}
		else if(s[0] == 'a') F.add_edge(a,b);
		else F.remove_edge(a,b);
	}
}
