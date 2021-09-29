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
vector<ll> t;
vector<bool> visited;
vector<vector<ll>> g, rg;
ll cnt = 0;
void dfs_first(ll crr) {
    visited[crr] = true;
    for (auto next : g[crr]) {
        if (visited[next]) continue;
        dfs_first(next);
    }
    t[cnt++] = crr;
    return;
}
void dfs_second(ll crr, vector<ll>& c) {
    visited[crr] = true;
    for (auto next : rg[crr]) {
        if (visited[next]) continue;
        dfs_second(next, c);
    }
    c.pb(crr);
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    g.resize(n), rg.resize(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        rg[b].pb(a);
    }
    t.resize(n);
    visited.assign(n, false);

    rep(i, n) {
        if (visited[i]) continue;
        dfs_first(i);
    }
    visited.assign(n, false);
    ll res = 0;
    rrep(i, n) {
        if (visited[t[i]]) continue;
        vector<ll> c;
        dfs_second(t[i], c);
        ll k = c.size();
        if (k > 1) { res += k * (k - 1) / 2; }
    }
    cout << res << endl;
    return 0;
}