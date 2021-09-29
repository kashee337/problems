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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> G(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    int k;
    cin >> k;
    vector<ll> c(k);
    rep(i, k) {
        cin >> c[i];
        c[i]--;
    }

    vector<vector<ll>> dist(k, vector<ll>(k));
    queue<ll> q;

    rep(i, k) {
        q.push(c[i]);
        vector<ll> tmp_dist(n, INF);
        tmp_dist[c[i]] = 0;
        while (!q.empty()) {
            ll crr = q.front();
            q.pop();
            for (auto next : G[crr]) {
                if (tmp_dist[crr] + 1 < tmp_dist[next]) {
                    tmp_dist[next] = tmp_dist[crr] + 1;
                    q.push(next);
                }
            }
        }
        rep(j, k) dist[i][j] = tmp_dist[c[j]];
    }

    // bitdp
    ll max_s = 1 << k;
    vector<vector<ll>> dp(max_s, vector<ll>(k, INF));
    rep(i, k) dp[1 << i][i] = 1;
    reps(bit, max_s, 1) {
        rep(i, k) {
            if ((bit >> i) & 1) {
                ll target_bit = 1 << i;
                ll bit2 = bit ^ target_bit;
                rep(j, k) {
                    if ((bit2 >> j) & 1) { dp[bit][i] = min(dp[bit][i], dp[bit2][j] + dist[i][j]); }
                }
            }
        }
    }
    ll res = INF;
    for (ll val : dp[max_s - 1]) res = min(res, val);
    if (res == INF) res = -1;
    cout << res << endl;
    return 0;
}