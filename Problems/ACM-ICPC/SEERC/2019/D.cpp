 #include<bits/stdc++.h>
 using namespace std;
 const int NC=26;
 int main()
 {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,i;
	string s;
	cin>>s;
	n=s.size();
	vector<pair<int,int>>v(NC,{0,0});
	for(i=0;i<n;i++)
		v[s[i]-'a'].first++;
	for(i=0;i<NC;i++)
		v[i].second=i;
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	sort(s.begin(),s.end());
	if(v[0].first<=n/2)cout<<"YES\n"<<s<<'\n';
	else
	{
		if(v[1].first<3 && v[2].first==0)cout<<"NO\n";
		else
		{
			s="";
			while(v[1].first>1)
			{
				s+=char(v[1].second+'a');
				v[1].first--;
			}
			for(i=2;i<NC;i++)
			{
				while(v[i].first--)
					s+=char(v[i].second+'a');
			}
			while((int)s.size()<n/2)
			{
				s+=char(v[0].second+'a');
				v[0].first--;
			}
			s+=char(v[1].second+'a');
			while(v[0].first--)
				s+=char(v[0].second+'a');
			cout<<"YES\n"<<s<<'\n';
		}
	}
}
