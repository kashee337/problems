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
constexpr int MOD = 998244353;
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
    ll n, m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<ll> u(m), v(m);
    rep(i, m) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        uf.merge(u[i], v[i]);
    }
    vector<ll> edge_num(n, 0);
    set<ll> roots;
    rep(i,n) {
        roots.insert(uf.root(i));
    }
    rep(i, m) {
        ll root = uf.root(u[i]);
        edge_num[root]++;
        roots.insert(root);
    }
    ll res = 1;
    for(ll root:roots){
        if (edge_num[root] != uf.size(root)) {
            cout << 0 << endl;
            return 0;
        }
        res *= 2;
        res %= MOD;
    }

    cout << res << endl;
    return 0;
}
