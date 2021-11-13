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
    vector<vector<ll>> g(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    ll q;
    ll B = sqrtl(2 * m);
    vector<bool> t(n, false);
    rep(i, n) if (g[i].size() >= B) t[i] = true;
    vector<vector<ll>> _g(n);
    rep(i, n) {
        for (auto to : g[i]) {
            if (t[to]) _g[i].pb(to);
        }
    }
    vector<ll> v(n, 1), d(n, -1);
    cin >> q;
    vector<ll> x(q), y(q);
    vector<ll> res(q);
    rep(i, q) {
        cin >> x[i] >> y[i];
        x[i]--;
        if (t[x[i]]) {
            res[i] = v[x[i]];
            v[x[i]] = y[i];
            for (auto to : _g[x[i]]) { v[to] = y[i]; }
            d[x[i]] = i;
        } else {
            ll idx = d[x[i]];
            for (auto to : g[x[i]]) {
                idx = max(idx, d[to]);
                if (t[to]) v[to] = y[i];
            }
            d[x[i]] = i;
            if (idx == -1)
                res[i] = 1;
            else
                res[i] = y[idx];
        }
    }
    for (auto v : res) cout << v << endl;

    return 0;
}