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
  vector<long long> v(n), used(n, 0);
  long long ans = 0;
  priority_queue<pair<int, int>> q;
  for(int i = 0; i < n; i++)
  {
    cin >> v[i];
    q.push({-v[i], i});
    ans = min(ans, -v[i]);
  }
  while(q.size())
  {
    int curr = -q.top().first;
    int id = q.top().second;
    q.pop();
    used[id] = 1;
    if(used[(id + 1) % n] == 1) ans += curr;
    if(used[(id - 1 + n) % n] == 1) ans += curr;
  }
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
