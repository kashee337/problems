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
constexpr int MOD = 1000000007;
vector<char> c;
vector<vector<int>> g;
int n;
class mint {
    long long x;

  public:
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
vector<vector<mint>> dp;
void dfs(int from, int crr) {
    int _c = c[crr] - 'a';
    if (g[crr].size() == 1 && g[crr][0] == from) {
        dp[crr][_c] = 1;
        return;
    }
    dp[crr][_c] = 1;
    dp[crr][2] = 1;
    for (auto to : g[crr]) {
        if (to == from) continue;
        dfs(crr, to);
        dp[crr][_c] *= (dp[to][_c] + dp[to][2]);
        dp[crr][2] *= (dp[to][0] + dp[to][1] + dp[to][2] + dp[to][2]);
    }
    dp[crr][2] -= dp[crr][_c];
    return;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    c.resize(n);
    g.resize(n);
    rep(i, n) cin >> c[i];
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dp.resize(n, vector<mint>(3, 0));
    dfs(-1, 0);
    cout << dp[0][2] << endl;
    return 0;
}