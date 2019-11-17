#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>get(multiset<pair<int,int>>&a,multiset<pair<int,int>>&b,bool l)
{
    vector<pair<int,int>>ans(b.size());
    int i=0;
    while(b.size())
    {
        auto x=b.begin();
        auto it=a.begin();
        if(l)
        {
            it=a.lower_bound({x->first,0});
            if(it==a.begin())return vector<pair<int,int>>(0);
            it--;
        }
        else
        {
            it=a.upper_bound({x->first+1,0});
            if(it==a.end())return vector<pair<int,int>>(0);
        }
        ans[i].first=it->second;
        ans[i++].second=x->second;
        a.erase(it);
        b.erase(x);
    }
    if(l)
        for(auto &x:ans)
            swap(x.first,x.second);
    return ans;
}
int main()
{
    int n,k,i;
    cin>>n;
    vector<pair<int,pair<int,int>>>a[2];
    a[0]=a[1]=vector<pair<int,pair<int,int>>>(n);
    for(k=0;k<2;k++)
    {
        for(i=0;i<n;i++)
            cin>>a[k][i].first;
        for(i=0;i<n;i++)
        {
            cin>>a[k][i].second.first;
            a[k][i].second.second=i+1;
        }
    }
    sort(a[0].begin(),a[0].end());
    sort(a[1].begin(),a[1].end());
    vector<pair<int,int>>ans,cans;
    multiset<pair<int,int>>s[2];
    int j[2]={0,0};
    for(i=0;i<n;i++)
    {
        for(k=0;k<2;k++)
            if(s[k].empty())
            {
                s[k].insert({a[k][j[k]].second.first,a[k][j[k]].second.second});
                for(j[k]++;j[k]<n && a[k][j[k]].first==a[k][j[k]-1].first;j[k]++)
                    s[k].insert({a[k][j[k]].second.first,a[k][j[k]].second.second});
            }
        if(s[0].size()<s[1].size())cans=get(s[1],s[0],1);
        else cans=get(s[0],s[1],0);
        ans.insert(ans.end(),cans.begin(),cans.end());
    }
    if((int)ans.size()!=n)
    {
        cout<<"impossible\n";
        return 0;
    }
    for(i=0;i<(int)ans.size();i++)
        cout<<ans[i].first<<" \n"[i==(int)ans.size()-1];
    for(i=0;i<(int)ans.size();i++)
        cout<<ans[i].second<<" \n"[i==(int)ans.size()-1];
}
