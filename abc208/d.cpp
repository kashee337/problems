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
vector<vector<pair<ll, ll>>> g;
ll n, m;
// ll solve(ll s, ll t, ll k) {
//     if (s == t) return 0;
//     priority_queue<pair<ll, ll>> q;
//     vector<bool> used(n, false);
//     ll res = 0;
//     reps(i, n, k + 1) {
//         if (i == s || i == t) continue;
//         used[i] = true;
//     }
//     q.push({0, s});
//     while (!q.empty()) {
//         auto v = q.top();
//         q.pop();
//         ll crr_cost = -v.first;
//         ll crr_v = v.second;
//         if (crr_v == t) {
//             res = crr_cost;
//             break;
//         }
//         if (used[crr_v]) continue;
//         used[crr_v] = true;
//         for (auto next : g[crr_v]) {
//             ll next_cost = next.second;
//             ll next_v = next.first;
//             q.push({-(crr_cost + next_cost), next_v});
//         }
//     }

//     return res;
// }
ll solve(ll s, ll t) {
    priority_queue<pair<ll, ll>> q;
    vector<bool> used(n, true);
    used[s] = false;
    used[t] = false;
    ll res = INF;
    q.push({0, s});

    while (!q.empty()) {
        auto v = q.top();
        q.pop();
        ll crr_cost = -v.first;
        ll crr_v = v.second;
        if (used[crr_v]) continue;
        used[crr_v] = true;
        if (crr_v == t) { return crr_cost; }
        for (auto next : g[crr_v]) {
            ll next_cost = next.second;
            ll next_v = next.first;
            q.push({-(crr_cost + next_cost), next_v});
        }
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    g.resize(n);
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb({b, c});
    }

    vector<vector<ll>> paths(n, vector<ll>(n));
    ll res = 0;
    rep(s, n) rep(t, n) {
        paths[s][t] = solve(s, t);
        if (paths[s][t] == INF) continue;
    }

    rep(k, n) {
        rep(s, n) {
            rep(t, n) {
                if (s == t) continue;
                rep(d, k + 1) { paths[s][t] = min(paths[s][t], paths[s][d] + paths[d][t]); }
                if (paths[s][t] == INF) continue;
                res += paths[s][t];
            }
        }
    }
    cout << res << endl;

    return 0;
}