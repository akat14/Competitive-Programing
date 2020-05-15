#include<bits/stdc++.h>
using namespace std;
bool prime(long long x)
{
	if(x%2==0)return 0;
	for(long long i=3;i*i<=x;i+=2)
		if(x%i==0)return 0;
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n,k,p,x,i,j,l;
	vector<long long>e,ne;
	while(cin>>x>>k)
	{
		/*if(!prime(x))
		{
			cout<<"0\n";
			continue;
		}*/
		p=1;
		n=x;
		while(n)
		{
			p*=10;
			n/=10;
		}
		e.push_back(x);
		for(i=0;i<k;i++)
		{
			for(j=0;j<(int)e.size();j++)
				for(l=1;l<10;l++)
					if(prime(l*p+e[j]))ne.emplace_back(l*p+e[j]);
			e=ne;
			ne.clear();
			p*=10;
		}
		sort(e.begin(),e.end());
		if(e.size()==0)cout<<"0\n";
		else
		{
			for(i=0;i<(int)e.size();i++)
			{
				if(i)cout<<" ";
				cout<<e[i];
			}
			cout<<'\n';
		}
		e.clear();
	}
}
