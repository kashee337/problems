#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>

#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n, s) for (int i = (s); i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define rreps(i, n, s) for (int i = s; i >= n; i--)

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 998244353;
class mint
{
  long long x;

public:
  mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint &a)
  {
    if ((x += a.x) >= MOD)
      x -= MOD;
    return *this;
  }
  mint &operator-=(const mint &a)
  {
    if ((x += MOD - a.x) >= MOD)
      x -= MOD;
    return *this;
  }
  mint &operator*=(const mint &a)
  {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint &a) const
  {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint &a) const
  {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint &a) const
  {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const
  {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }
  // for prime MOD
  mint inv() const { return pow(MOD - 2); }
  mint &operator/=(const mint &a) { return (*this) *= a.inv(); }
  mint operator/(const mint &a) const
  {
    mint res(*this);
    return res /= a;
  }

  friend ostream &operator<<(ostream &os, const mint &m)
  {
    os << m.x;
    return os;
  }
};
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v(k);
  rep(i, k)
  {
    cin >> v[i].first >> v[i].second;
  }
  vector<mint> dp(n + 1, 0);
  dp[0] = 1;
  reps(i, n, 1)
  {
    //現在の位置の値を更新
    dp[i] += dp[i - 1];

    //現在の位置の値を配る
    for (auto p : v)
    {
      //境界インデックスを計算
      int l = i + p.first;
      int r = i + p.second + 1;
      if (l > n) continue;//左境界の領域外判定
      dp[l] += dp[i];
      if(r > n+1) continue;//右境界の領域外判定
      dp[r] -= dp[i];
    }
  }
  cout << dp[n] << endl;
  return 0;
}