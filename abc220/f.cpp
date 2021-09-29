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
vector<pair<ll, ll>> score;
vector<ll> res;
vector<vector<int>> g;
pair<ll, ll> dfs_score(int from, int crr, int depth) {
    pair<ll, ll> v = {0, 0};
    for (auto to : g[crr]) {
        if (to == from) continue;
        auto tmp = dfs_score(crr, to, depth + 1);
        v.first += 1 + tmp.first;
        v.second += 1 + tmp.first + tmp.second;
    }
    score[crr] = v;
    return v;
}
ll dfs(int from, int crr, int depth) {
    if (from != -1) {
        res[crr] = score[crr].second + 1;
        if (g[from].size() >= 2) {
            res[crr] += (score[from].first - score[crr].first - 1) + (res[from] - score[crr].second - 1);
        }
    }
    for (auto to : g[crr]) {
        if (to == from) continue;
        dfs(crr, to, depth + 1);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    g.resize(n);
    rep(i, n - 1) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    score.resize(n);
    dfs_score(-1, 0, 0);
    res.resize(n);
    res[0] = score[0].second;
    dfs(-1, 0, 0);
    for (auto v : res) cout << v << endl;
    return 0;
}
// 10
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 3 7
// 3 8
// 7 9
// 9 10