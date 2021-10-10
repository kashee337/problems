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
ll n, m, k;
vector<vector<ll>> g;
vector<ll> depth;
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
void dfs(ll crr, ll from, ll d) {
    depth[crr] = d;
    for (auto to : g[crr]) {
        if (to == from) continue;
        dfs(to, crr, d + 1);
    }
}
vector<ll> get_path(int start, int goal) {
    vector<ll> path(n, -1);
    queue<pair<ll, ll>> q;
    q.push({start, -1});
    while (!q.empty()) {
        ll crr = q.front().first;
        ll from = q.front().second;
        q.pop();
        if (path[crr] >= 0) continue;
        path[crr] = from;
        if (crr == goal) break;
        for (ll to : g[crr]) { q.push({to, crr}); }
    }
    vector<ll> res;
    ll crr = goal;
    while (crr != start) {
        if (depth[crr] < depth[path[crr]]) {
            res.pb(path[crr]);
        } else {
            res.pb(crr);
        }
        crr = path[crr];
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    vector<ll> a(m);
    rep(i, m) {
        cin >> a[i];
        a[i]--;
    }
    g.resize(n);
    depth.resize(n, 0);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0, -1, 0);
    map<ll, ll> pathlist;
    rep(i, m - 1) {
        vector<ll> path = get_path(a[i], a[i + 1]);
        for (auto v : path) { pathlist[v]++; }
    }
    vector<vector<mint>> dp(n + 1, vector<mint>(100005, 0));
    dp[1][0] = 1;
    ll sum = 0;
    reps(i, n, 1) {
        ll v = pathlist[i];
        rep(j, 100005) {
            if (j - v >= 0) { dp[i + 1][j] += dp[i][j - v]; }
            dp[i + 1][j] += dp[i][j];
        }
        sum += v;
    }
    mint res = 0;
    rep(j, sum + 1) {
        if (j - (sum - j) == k) { res += dp[n][j]; }
    }
    cout << res << endl;
    return 0;
}