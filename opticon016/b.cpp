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
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll v = 0;
    rep(i, n) {
        cin >> a[i];
        v += a[i];
    }
    if (v % n != 0)
        cout << -1 << endl;
    else {
        UnionFind uf(n);
        vector<ll> group_n(n, 0);
        rep(i, n) group_n[i] = a[i];
        ll res = 0;
        rep(i, n - 1) {
            ll crr_v = group_n[uf.root(i)];
            ll crr_l = uf.size(i);
            ll next_v = group_n[uf.root(i + 1)];
            if (crr_v % crr_l != 0 || crr_v / crr_l != v / n) {
                uf.merge(i, i + 1);
                res++;
                int idx = uf.root(i);
                if (uf.size(i) == 2) { crr_v = idx == i ? next_v : crr_v; }
                group_n[idx] += next_v;
            }
        }
        cout << res << endl;
    }

    return 0;
}