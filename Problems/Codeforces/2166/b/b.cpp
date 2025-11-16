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
  long long a, b, n;
  cin >> a >> b >> n;
  if(a == b)
  {
    cout << "1\n";
    return;
  }
  int ans = 1;
  if(a / n < b) ans++;
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
