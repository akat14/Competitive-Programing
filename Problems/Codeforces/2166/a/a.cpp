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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for(int i = 0; i < n; i++)
    if(s[i] != s[n - 1]) ans++;
  cout << ans << '\n';
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
