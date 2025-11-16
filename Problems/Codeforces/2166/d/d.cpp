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
const long long MOD = 998244353;
void solve()
{
  long long n;
  cin >> n;
  vector<long long> v(n);
  read(v);
  sort(v.begin(), v.end());
  long long curr = 1;
  vector<pair<long long, long long>> p;
  for(int i = 1; i < n; ++i)
  {
    if(v[i] != v[i - 1])
    {
      p.push_back({curr, v[i - 1]});
      curr = 1;
    }
    else ++curr;
  }
  p.push_back({curr, v.back()});
  sort(p.begin(), p.end());
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
  dp[0][0] = 1;
  long long i = 1, j, count;
  for(i = 1; i <= p.size(); i++)
  {
    dp[i][0] = 1;
    count = p[i - 1].first;
    if(count == p.back().first) break;
    for(j = 0; j < count; j++)
      dp[i][j] = dp[i - 1][j];
    for(j = count; j <= n; j++)
      dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - count] * count) % MOD;
    for(j = j - count + 1; j <= n; j++)
      dp[i][n] = (dp[i][n] + dp[i][j] * count) % MOD;
  }
  long long ans = 0, oi = i;
  for(j = p.back().first; j <= n; j++)
  {
    ans += dp[i - 1][j];
    if(ans >= MOD) ans -= MOD;
  }
  for(; i <= p.size(); i++)
  {
    dp[i][0] = 1;
    for(j = count; j <= n; j++)
      dp[i][j] = (dp[oi - 1][j - count] * count) % MOD;
    for(j = j - count + 1; j <= n; j++)
    {
      dp[i][n] += dp[oi - 1][j];
      if(dp[i][n] >= MOD) dp[i][n] -= MOD;
    }
    if(i == oi) continue;
    for(j = count + 1; j <= n; j++)
      dp[i][j] = (dp[i][j] + dp[i - 1][j - count] * count) % MOD;
    for(j = 1; j <= n; j++)
    {
      dp[i][j] += dp[i - 1][j];
      if(dp[i][j] >= MOD) dp[i][j] -= MOD;
    }
  }
  for(j = 1; j <= n; j++)
  {
    ans += dp[i - 1][j];
    if(ans >= MOD) ans -= MOD;
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
