 #include<bits/stdc++.h>
 using namespace std;
 const int NC=26;
 int main()
 {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,h,i,j,k;
	cin>>n>>m>>h;
	vector<vector<bool>>a(n,vector<bool>(m)),b(n,vector<bool>(h));
	vector<int>u(n,0),u2(n,0);
	char c;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cin>>c;
			a[i][j]=c-'0';
			u[i]+=a[i][j];
		}
	for(i=0;i<n;i++)
		for(k=0;k<h;k++)
		{
			cin>>c;
			b[i][k]=c-'0';
			u2[i]+=b[i][k];
		}
	int mi=0,ma=0;
	for(i=0;i<n;i++)
	{
		ma+=u[i]*u2[i];
		mi+=max(u[i],u2[i]);
		if((u[i]>0)!=(u2[i]>0))
		{
			cout<<"-1\n";
			return 0;
		}
	}
	cout<<ma<<'\n';
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			for(k=0;k<h;k++)
				if(a[i][j] && b[i][k])
					cout<<i<<" "<<j<<" "<<k<<'\n';
	cout<<mi<<'\n';
	for(i=0;i<n;i++)
	{
		if(u[i]==0)continue;
		if(u[i]>u2[i])
		{
			k=0;
			while(!b[i][k])
				k++;
			u2[i]--;
			b[i][k]=0;
			for(j=0;j<m;j++)
				if(a[i][j])
				{
					cout<<i<<" "<<j<<" "<<k<<'\n';
					u[i]--;
					a[i][j]=0;
					if(u[i]==u2[i])break;
				}
		}
		if(u[i]<u2[i])
		{
			j=0;
			while(!a[i][j])
				j++;
			u[i]--;
			a[i][j]=0;
			for(k=0;k<h;k++)
				if(b[i][k])
				{
					cout<<i<<" "<<j<<" "<<k<<'\n';
					u2[i]--;
					b[i][k]=0;
					if(u[i]==u2[i])break;
				}
		}
		for(j=0;j<m;j++)
			for(k=0;k<h;k++)
				if(a[i][j] && b[i][k])
				{
					cout<<i<<" "<<j<<" "<<k<<'\n';
					a[i][j]=0;
					b[i][k]=0;
				}
	}
}
