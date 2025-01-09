#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n=100,h=100;
  ofstream fout;
  map<pair<int,int>,int>m;
  for(int i=0;i<=10;i++)
  {
      srand(i);
      string s = "fat0.in";
      s[3] = i +'0';
      fout.open(s);
      fout<<h<<" "<<n<<endl;
      for(int j=0;j<n;j++)
      {
          int x=rand()%h;
          int y=rand()%h;
          if(m.find({x,y})!=m.end())
          {
            j--;
            continue;
          }
          m[{x,y}]=1;
          fout<<x<<" "<<y<<endl;
      }
      fout.close();
  }
}

