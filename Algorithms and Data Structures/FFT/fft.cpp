vector<complex<double>>get(vector<complex<double>>&a,int i)
{
	vector<complex<double>>ans;
	for(;i<(int)a.size();i+=2)
		ans.push_back(a[i]);
	return ans;
}
//w=(cos(2*pi/n),sin(2*pi/n)) and w=(cos(-2*pi/n),sin(*2*pi/n)) for ifft
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
