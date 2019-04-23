#include<bits/stdc++.h>
using namespace std;
long long c;
long long pow(long long a,long long x)
{
	long long ans=1;
	for(;x;x>>=1)
	{
		if(x&1)ans=(ans*a)%c;
		a=(a*a)%c;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a,b;
	cin>>a>>b>>c;
	cout<<pow(a,b)<<'\n';;
}
