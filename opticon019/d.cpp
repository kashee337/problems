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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<map<ll, ll>> g(n);
    UnionFind uf(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a][b]++;
        g[b][a]++;
        uf.merge(a, b);
    }
    vector<ll> res(n, 0);
    rep(i, k) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        if (uf.issame(a, b) && !g[a].count(b)) {
            res[a]--;
            res[b]--;
        }
    }
    rep(i, n) { res[i] += uf.size(i) - g[i].size() - 1; }
    rep(i, n) { cout << res[i] << endl; }
    return 0;
}