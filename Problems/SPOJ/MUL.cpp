#include<bits/stdc++.h>
using namespace std;
void read(vector<complex<double>>&a)
{
	string s;
	int i,n;
	cin>>s;
	n=s.size();
	for(i=0;i<n;i++)
		a.push_back(complex<double>(s[n-i-1]-'0',0));
}
vector<complex<double>>get(vector<complex<double>>&a,int i)
{
	vector<complex<double>>ans;
	for(;i<(int)a.size();i+=2)
		ans.push_back(a[i]);
	return ans;
}
vector<complex<double>>fft(vector<complex<double>>a,complex<double>w)
{
	if(a.size()==1)return a;
	vector<complex<double>>even,odd;
	even=fft(get(a,0),w*w);
	odd=fft(get(a,1),w*w);
	int n=a.size(),i;
	complex<double>x(1,0);
	for(i=0;i<n/2;i++)
	{
		a[i]=even[i]+x*odd[i];
		a[i+n/2]=even[i]-x*odd[i];
		x*=w;
	}
	return a;
}
void solve()
{
	const double pi=acos(-1);
	vector<complex<double>>a,b;
	int n,i;
	read(a);
	read(b);
	n=a.size()+b.size();
	for(;(n-1)&n;n++){}
	a.resize(n);
	b.resize(n);
	double ang=pi*2.0/double(n);
	complex<double>w(cos(ang),sin(ang));
	a=fft(a,w);
	b=fft(b,w);
	for(i=0;i<n;i++)
		a[i]*=b[i];
	a=fft(a,complex<double>(cos(-ang),sin(-ang)));
	vector<int>ans(n);
	int carry=0;
	for(i=0;i<n;i++)
	{
		ans[i]=carry+round(real(a[i])/n);
		carry=ans[i]/10;
		ans[i]%=10;
	}
	int l=0;
	if(carry)
	{
		l=1;
		cout<<carry;
	}
	for(i=n-1;i>=0;i--)
	{
		if(ans[i])l=1;
		if(l)cout<<ans[i];
	}
	if(l==0)cout<<0;
	cout<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
		solve();
}
