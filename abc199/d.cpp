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

void dfs(ll crr) {
    ll k = 0;
    for (auto to : g[crr]) {
        if (visited[to]) { k++; }
    }
    colors[crr] = k <= 3 ? 3 - k : 0;

    visited[crr] = true;
    for (auto to : g[crr]) {
        if (visited[to]) continue;
        dfs(to);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    g.resize(n);

    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    ll res = -1;
    rep(i, n) {
        queue<ll> q;
        vector<ll> visited(n, false);
        vector<ll> colors(n, 3);
        q.push(i);
        while (!q.empty()) {
            ll crr = q.front();
            q.pop();
            if (visited[crr]) continue;
            ll k = 0;
            for (auto to : g[crr]) {
                if (visited[to]) { k++; }
            }
            colors[crr] = k <= 3 ? 3 - k : 0;
            visited[crr] = true;
            for (auto to : g[crr]) {
                if (visited[to]) continue;
                q.push(to);
            }
        }
        // dfs(0);
        ll tmp = 1;
        for (ll c : colors) { tmp *= c; }
        if (res < tmp) res = tmp;
    }

    cout << res << endl;

    return 0;
}
