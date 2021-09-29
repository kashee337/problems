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
vector<vector<ll>> g;
vector<ll> a, b;
vector<ll> depth;
vector<ll> dp;
void depth_dfs(int crr, int d) {
    depth[crr] = d;
    for (int next : g[crr]) {
        if (depth[next] > -1) continue;
        depth_dfs(next, d + 1);
    }
}

void imos_dfs(int crr, ll v) {
    dp[crr] += v;
    for (int next : g[crr]) {
        if (depth[crr] > depth[next]) continue;
        imos_dfs(next, dp[crr]);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    g.resize(n);
    a.resize(n - 1), b.resize(n - 1);
    depth.assign(n, -1);
    dp.assign(n, 0);
    rep(i, n - 1) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        g[a[i]].pb(b[i]);
        g[b[i]].pb(a[i]);
    }
    depth_dfs(0, 0);
    int q;
    cin >> q;

    rep(i, q) {
        int t, e, x;
        cin >> t >> e >> x;
        e--;
        int va, vb;
        if (t == 1) {
            va = a[e];
            vb = b[e];
        } else {
            va = b[e];
            vb = a[e];
        }

        if (depth[va] < depth[vb]) {
            dp[0] += x;
            dp[vb] -= x;
        } else {
            dp[va] += x;
        }
    }

    imos_dfs(0, 0);
    for (auto v : dp) { cout << v << endl; }
    return 0;
}
