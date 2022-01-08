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
vector<vector<ll>> g;
vector<bool> used;
vector<ll> d;
struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(int x, int y) { return root(x) == root(y); }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);  // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) { return -par[root(x)]; }
};
void dfs(int from, int crr) {
    if (used[crr]) return;
    d.pb(crr + 1);
    used[crr] = true;
    if (g[crr].size() > 2) return;
    for (int next : g[crr]) {
        if (next == from) continue;
        dfs(crr, next);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    g.resize(n);
    used.assign(n, false);
    vector<ll> deg(n, 0);
    UnionFind uf(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
        deg[a]++, deg[b]++;
        uf.merge(a, b);
    }
    vector<ll> crr;
    vector<bool> t(n, false);
    rep(i, n) {
        int root = uf.root(i);
        if (t[root]) continue;
        if (deg[i] == 1) {
            crr.pb(i);
            t[root] = true;
        }
    }
    bool ok = true;
    rep(i, n) {
        if (uf.size(i) > 1) {
            int root = uf.root(i);
            if (!t[root]) ok = false;
        }
    }
    for (int c : crr) {
        dfs(-1, c);
        if (d.size() != uf.size(c)) ok = false;
        d.clear();
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}