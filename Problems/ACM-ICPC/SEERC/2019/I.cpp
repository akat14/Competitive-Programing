 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int>a(n),b(n);
	for(auto &x:a)
		cin>>x;
	for(auto &x:b)
		cin>>x;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int i=0,ans=0;
	for(auto x:a)
	{
		while(i!=n-1 && abs(x-b[i])>=abs(x-b[i+1]))
			i++;
		ans=max(ans,abs(x-b[i]));
	}
	cout<<ans<<'\n';
}
