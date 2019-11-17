#include<bits/stdc++.h>
using namespace std;
const int I=1e6;
struct SegmentTree
{
    int n;
    vector<int>it;
    vector<int>lazy;
    SegmentTree(int nn)
    {
        n=nn;
        it.resize(4*n);
        lazy.resize(4*n);
    }
    void push(const int &x)
    {
        if(lazy[x])
        {
            it[x]-=lazy[x];
            if(x<n*2)
            {
                lazy[x*2]=lazy[x*2]+lazy[x];
                lazy[x*2+1]=lazy[x*2+1]+lazy[x];
            }
            lazy[x]=0;
        }
    }
    void up(int x,int l,int r,const int &L,const int &R)
    {
        push(x);
        if(L<=l && r<=R)
        {
            lazy[x]=1;
            return;
        }
        if(L<=(l+r)/2)up(x*2,l,(l+r)/2,L,R);
        if(R>(l+r)/2)up(x*2+1,(l+r)/2+1,r,L,R);
        push(x*2);
        push(x*2+1);
        it[x]=max(it[x*2],it[x*2+1]);
    }
    void update(int l,int r)
    {
        up(1,0,n-1,l,r);
    }
    int q(int x,int l,int r)
    {
        push(x);
        if(l==r)return l;
        push(2*x);
        push(2*x+1);
        if(it[x*2]>=it[x*2+1])return q(x*2,l,(l+r)/2);
        return q(x*2+1,(l+r)/2+1,r);
    }
    int query()
    {
        return q(1,0,n-1);
    }
};
int main()
{
    int n,i,k,j,ans=0,s;
    cin>>n;
    SegmentTree T(n);
    char ch;
    vector<vector<pair<int,int>>>v(I);
    for(i=0;i<n;i++)
    {
        cin>>ch>>k;
        v[k-1].push_back({(ch=='s')-(ch=='e'),i});
    }
    int mi,c;
    for(i=0;i<I;i++)
    {
        mi=0,c=0;
        for(j=0;j<(int)v[i].size();j++)
        {
            c+=v[i][j].first;
            mi=min(mi,c);
        }
        if(c!=0 || v[i].empty())continue;
        ans++;
        if(mi!=0)
        {
            c=mi;
            for(j=v[i].size()-1;c<0;j--)
                c+=v[i][j].first;
            s=j+1;
        }
        else s=0;
        c=0;
        int cs=v[i][s].second+1;
        for(j=s;j<(int)v[i].size();j++)
        {
            c+=v[i][j].first;
            if(c==0)
            {
                T.update(cs,v[i][j].second);
                if(j+1<(int)v[i].size())cs=v[i][j+1].second+1;
                else cs=v[i][0].second+1;
            }
        }
        if(c!=0)
        {
            if(cs<n)T.update(cs,n-1);
            cs=0;
        }
        for(j=0;j<s;j++)
        {
            c+=v[i][j].first;
            if(c==0)
            {
                T.update(cs,v[i][j].second);
                cs=v[i][j+1].second+1;
            }
        }
    }
    cout<<T.query()+1<<" "<<ans+T.it[1]<<'\n';
}


