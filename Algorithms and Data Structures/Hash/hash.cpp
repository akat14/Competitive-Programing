long long st[3]={127,131,137};
long long mod[3]={123457,(long long)(1e7+7),(long long)(1e7+9)};
vector<long long>de[3];
void init(int n)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		de[i].resize(n+1);
		de[i][0]=1;
		for(j=1;j<n+1;j++)
			de[i][j]=(de[i][j-1]*st[i])%mod[i];
	}
}
struct hash3
{
	long long h[3];
	int sz;
	hash3()
	{
		h[0]=h[1]=h[2]=0;
		sz=0;
	}
	hash3(string s)
	{
		h[0]=h[1]=h[2]=0;
		sz=0;
		for(int i=0;i<sz;i++)
			(*this)+=hash3(s[i]);
	}
	hash3(char c)
	{
		h[0]=h[1]=h[2]=c;
		sz=1;
	}
	hash3 operator=(hash3 const &x)
	{
		for(int i=0;i<3;i++)
			h[i]=x.h[i];
		sz=x.sz;
		return *this;
	}
	hash3 operator+(hash3 x)
	{
		hash3 ans;
		for(int i=0;i<3;i++)
			ans.h[i]=(h[i]*de[i][x.sz]+x.h[i])%mod[i];
		ans.sz=sz+x.sz;
		return ans;
	}
	hash3 operator+=(hash3 x)
	{
		(*this)=(*this)+x;
		return *this;
	}
	hash3 operator-(const hash3 &x)
	{
		hash3 ans;
		for(int i=0;i<3;i++)
		{
			ans.h[i]=h[i]-(de[i][sz-x.sz]*x.h[i])%mod[i];
			if(ans.h[i]<0)ans.h[i]+=mod[i];
		}
		ans.sz=sz-x.sz;
		return ans;
	}
	hash3 operator-=(hash3 x)
	{
		(*this)=(*this)-x;
		return *this;
	}
	bool operator==(hash3 const &a)
	{
		int i;
		for(i=0;i<3;i++)
			if(this->h[i]!=a.h[i])return 0;
		return 1;
	}
};