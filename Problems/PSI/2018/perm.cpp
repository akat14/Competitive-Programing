#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1,MOD=(1e9)+7;
int a[MAXN],br[MAXN];
int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n,i,cbr,j,c;
        long long ans=1;
        cin>>n;
        for(i=1;i<=n;i++)
                cin>>a[i];
        for(i=1;i<=n;i++)
        {
                cbr=0;
                j=i;
                while(a[j]!=-1)
                {
                        c=a[j];
                        a[j]=-1;
                        j=c;
                        cbr++;
                }
                br[cbr]++;
        }
        for(i=1;i<=n;i++)
        {
                while(br[i])
                {
                        ans=(ans*br[i]*i)%MOD;
                        br[i]--;
                }
        }
        cout<<ans<<'\n';
}