#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(vector<T> &v)
{
  for(T &x : v)
    cin >> x;
}
template <typename T>
void print(vector<T> &v)
{
  for(T &x : v)
    cout << x << ' ';
  cout << '\n';
}
void solve()
{
  long long n, q, x, j, ans, y;
  cin >> n >> q;
  vector<long long> v(n);
  read(v);
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  priority_queue<long long> qu;
  for(int i = 0; i < q; i++)
  {
    cin >> x;
    vector<int> b;
    while(x)
    {
      b.push_back(x - (x & (x - 1)));
      x &= x - 1;
    }
    ans = 0;
    for(j = 0; j < b.size(); j++)
    {
      if(j < v.size()) qu.push(v[j]);
      else qu.push(0);
      x = qu.top();
      qu.pop();
      y = b[b.size() - 1 - j];
      if(x > y) qu.push(x - y);
      else ans += y - x;
    }
    while(qu.size())
      qu.pop();
    cout << ans << '\n';
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while(t--)
  {
    solve();
  }
}
