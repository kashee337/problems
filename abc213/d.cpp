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
vector<bool> used;
vector<ll> res;
void dfs(int from, int crr) {
    res.pb(crr + 1);
    for (int to : g[crr]) {
        if (to == from) continue;
        if (used[to]) continue;
        used[to] = true;
        dfs(crr, to);
        res.pb(crr + 1);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    g.resize(n);
    used.resize(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    rep(i, n) sort(g[i].begin(), g[i].end());
    dfs(-1, 0);
    rep(i, res.size() - 1) cout << res[i] << " ";
    cout << res[res.size() - 1] << endl;
    return 0;
}