#include<bits/stdc++.h>
using namespace std;
const int MAXN=(1<<19)+1;
int a[MAXN],b[MAXN],n;
long long get(int l1,int r1,int l2,int r2)
{
	long long ans=0;
	while(l1<=r1 && l2<=r2)
	{
		if(a[l1]<a[l2])l1++;
		else
		{
			ans+=r1-l1+1;
			l2++;
		}
	}
	return ans;
}
long long di(int l,int r)
{
	if(l==r)return 0;
	long long ans=di(l,(l+r)>>1)+di((l+r)/2+1,r)+min(get(l,(l+r)>>1,(l+r)/2+1,r),
												get((l+r)/2+1,r,l,(l+r)>>1));
	int p1=l,p2=(l+r)/2+1,p=0;
	while(p1<=(l+r)/2 && p2<=r)
	{
		if(a[p1]<a[p2])b[p++]=a[p1++];
		else b[p++]=a[p2++];
	}
	while(p1<=(l+r)/2)
		b[p++]=a[p1++];
	while(p2<=r)
		b[p++]=a[p2++];
	for(p=l;p<=r;p++)
		a[p]=b[p-l];
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int i;
	cin>>n;
	n=1<<n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	cout<<di(1,n)<<'\n';
}
