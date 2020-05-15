#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c,i,j,ans;
	while(cin>>a>>b>>c)
	{
		ans=0;
		for(i=1;i<=a;i++)
			for(j=1;j<=c;j++)
			{
				long long x=sqrt(i*j);
				if(x*x==i*j)x--;
				ans+=min(x,b);
			}
		cout<<ans<<endl;
	}
}
