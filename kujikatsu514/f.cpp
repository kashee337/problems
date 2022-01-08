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
    int a, b;
    rep(i, m) {
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<bool> used(n, false);
    deque<int> q;
    q.push_back(a);
    q.push_front(b);
    used[a] = true;
    used[b] = true;
    bool updated = true;
    while (updated) {
        updated = false;
        int a = q.front(), b = q.back();
        for (int to : g[a]) {
            if (used[to]) continue;
            q.push_front(to);
            used[to] = true;
            updated = true;
            break;
        }
        for (int to : g[b]) {
            if (used[to]) continue;
            q.push_back(to);
            used[to] = true;
            updated = true;
            break;
        }
    }
    cout << q.size() << endl;
    rep(i, q.size()) {
        int v = q[i];
        cout << v + 1 << endl;
    }
    return 0;
}