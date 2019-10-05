#include<iostream>
#include<vector>
using namespace std;
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
	 int i,j,n;
	 vector<long long>primes,sieve(n,-1);
	 for(i=2;i<n;i++)
	 {
		 if(s[i]==-1)
		 {
			 s[i]=p.size();
			 p.push_back(i);
		 }
		 for(j=0;j<=s[i] && p[j]*i<n;j++)
			 s[p[j]*i]=j;
	 }
}
