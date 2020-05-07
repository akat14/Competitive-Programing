#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long env[100001],l[100001];
struct ha
{
	int a;
	int b;
	int i;
}c[100002];
bool cmp(ha x,ha y)
{
	if(x.a==y.a)return x.b>y.b;
	return x.a<y.a;
}
double cross(int i,int j)
{
	double a1=1.0/double(c[i].a);
	double b1=1.0/double(c[i].b);
	double a2=1.0/double(c[j].a);
	double b2=1.0/double(c[j].b);
	return (b2-b1)/(a1-a2);
}
const double eps=1e-8;
int main()
{
	int n,i,o=0;
	cin>>n;
	for(i=0;i<n;i++)
    {
		cin>>c[i].a>>c[i].b;
		c[i].i=i;
	}
	sort(c,c+n,cmp);
	int r=0;
	env[r]=0;
	for(i=1;i<n;i++)
	{
		if(c[i].a==c[i-1].a)continue;
		env[++r]=i;
		while(r>1 && cross(env[r-2],env[r])<=cross(env[r-2],env[r-1]))
			env[--r]=i;
	}
	for(i=0;i<r;i++)
	{
		if(cross(env[i],env[i+1])>eps && !(c[env[i]].a==c[env[i]+1].a && c[env[i]].b==c[env[i]+1].b))
        {
			l[c[env[i]].i]=1;
			o++;
        }
	}
    if(!(c[env[i]].a==c[env[i]+1].a && c[env[i]].b==c[env[i]+1].b))
    {
		l[c[env[i]].i]=1;
		o++;
    }
    if(o==0)
    {
		cout<<-1<<endl;
		return 0;
    }
    int f=0;
    for(i=0;i<n;i++)
    {
		if(l[i] && f)cout<<' ';
		if(l[i])
		{
			f=1;
			cout<<i;
		
		}
	}
	cout<<endl;
}
