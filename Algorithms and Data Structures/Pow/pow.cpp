long long pow(long long a,long long x)
{
	long long ans=1;
	for(;x;x>>=1)
	{
		if(x&1)ans*=a;
		a*=a;
	}
	return ans;
}
