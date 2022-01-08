#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
vector<ll> c;
vector<vector<ll>> g;
bool dfs(int from, int crr, int v) {
    c[crr] = v;
    bool ng = false;
    for (int to : g[crr]) {
        if (to == from) continue;
        if (c[to] == -1) {
            ng |= dfs(crr, to, 1 - v);
        } else {
            if (c[to] == v) ng = true;
        }
    }
    return ng;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<string> s(n);
    c.assign(n, -1);
    rep(i, n) cin >> s[i];

    g.resize(n);
    rep(i, n) {
        reps(j, n, i + 1) {
            if (s[i][j] == '1') {
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }
    if (dfs(-1, 0, 0)) {
        cout << -1 << endl;
    } else {
        vector<vector<ll>> dp(n, vector<ll>(n, INF));
        rep(i, n) {
            rep(j, n) {
                if (s[i][j] == '1') {
                    dp[i][j] = 1;
                } else if (i == j) {
                    dp[i][j] = 0;
                }
            }
        }
        rep(k, n) {
            rep(i, n) {
                rep(j, n) { dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); }
            }
        }
        ll res = -INF;
        rep(i, n) {
            rep(j, n) { res = max(res, dp[i][j] + 1); }
        }
        cout << res << endl;
    }
    return 0;
}
