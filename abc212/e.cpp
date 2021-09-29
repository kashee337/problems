#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

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
class mint {
  public:
    long long x;
    mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint& a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res *= a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const { return pow(MOD - 2); }
    mint& operator/=(const mint& a) { return (*this) *= a.inv(); }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res /= a;
    }

    friend ostream& operator<<(ostream& os, const mint& m) {
        os << m.x;
        return os;
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<vector<mint>> dp(k + 1, vector<mint>(n, 0));
    dp[0][0] = 1;
    rep(step, k) {
        mint v1;
        rep(crr, n) { v1 += dp[step][crr]; }
        rep(crr, n) {
            mint v2 = dp[step][crr];
            for (auto to : g[crr]) { v2 += dp[step][to]; }
            dp[step + 1][crr] = v1 - v2;
        }
    }
    cout << dp[k][0] << endl;
    return 0;
}