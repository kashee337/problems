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
vector<ll> res;
void easy_dfs(int from, int crr) {
    if (res.size() == 2) return;
    res.pb(crr);
    for (int to : g[crr]) {
        if (from == to) continue;
        easy_dfs(crr, to);
    }
}
vector<bool> used;
vector<int> from_nodes;
void mid_dfs(int goal, int from, int crr) {
    if (used[crr]) return;
    from_nodes[crr] = from;
    used[crr] = true;
    for (int to : g[crr]) {
        if (from == to) continue;
        mid_dfs(goal, crr, to);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    g.resize(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int start;
    int v = 3;
    used.assign(n, false);
    rep(i, n) {
        if (g[i].size() == v) {
            start = i;
            v = g[i].size();
        }
    }
    if (v == 1) {
        easy_dfs(-1, start);
    } else {
        from_nodes.resize(n);
        int goal = g[start][1];
        mid_dfs(goal, -1, start);
        ll crr = from_nodes[goal];
        res.pb(goal);
        while (crr != -1) {
            res.pb(crr);
            crr = from_nodes[crr];
        }
    }
    cout << res.size() << endl;
    for (auto v : res) cout << v + 1 << endl;
    return 0;
}