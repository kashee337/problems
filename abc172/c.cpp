#include <bits/stdc++.h>

#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n, s) for (int i = (s); i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define rreps(i, n, s) for (int i = s; i >= n; i--)

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  vector<ll> sa(n+1, 0);
  vector<ll> sb(m+1, 0);
  rep(i, n ) { sa[i + 1] = sa[i] + a[i]; }
  rep(i, m ) { sb[i + 1] = sb[i] + b[i]; }
  ll ans = 0;
  rep(i, n+1) {
    ll t = k - sa[i];
    if (t >= 0) {
      auto it = upper_bound(sb.begin(), sb.end(), t);
      int j = distance(sb.begin(), it) - 1;
      ll num = (ll)(i) + (ll)(j);
      ans = max(ans, num);
    }
  }
  cout << ans << endl;
  return 0;
}