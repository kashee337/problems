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
constexpr int MOD = 998244353;
template <typename T> struct UnionFind {
    vector<T> _parent;
    vector<T> _size;
    UnionFind(T N) : _parent(N), _size(N, (T)1) { rep(i, N) _parent[i] = i; }
    void init(T N) {
        _parent.resize(N);
        _size.assign(N, (T)1);
        rep(i, N) _parent[i] = i;
    }

    T root(T x) {
        if (_parent[x] == x) return x;
        return _parent[x] = root(_parent[x]);
    }

    T size(T x) { return _size[root(x)]; }
    bool same(T x, T y) {
        T rx = root(x);
        T ry = root(y);
        return rx == ry;
    }
    bool unite(T x, T y) {
        T rx = root(x);
        T ry = root(y);
        if (rx == ry) return false;
        if (_size[rx] < _size[ry]) swap(rx, ry);
        if (_size[rx] == _size[ry]) { _size[rx]++; }
        _parent[ry] = rx;
        return true;
    }
    map<ll, ll> get_group() {
        map<ll, ll> group;
        rep(i, _parent.size()) group[_parent[i]]++;
        return group;
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    UnionFind<ll> uf_h(n), uf_w(n);
    rep(h_0, n) {
        rep(h_1, n) {
            if (h_0 == h_1) continue;
            bool ok = true;
            rep(w, n) {
                if (a[h_0][w] + a[h_1][w] > k) ok = false;
            }
            if (ok) uf_h.unite(h_0, h_1);
        }
    }
    rep(w_0, n) {
        rep(w_1, n) {
            if (w_0 == w_1) continue;
            bool ok = true;
            rep(h, n) {
                if (a[h][w_0] + a[h][w_1] > k) ok = false;
            }
            if (ok) uf_w.unite(w_0, w_1);
        }
    }
    ll res = 1;
    auto group_h = uf_h.get_group();
    auto group_w = uf_w.get_group();
    for (auto g : group_h) { reps(i, g.second + 1, 1) res = res * i % MOD; }
    for (auto g : group_w) { reps(i, g.second + 1, 1) res = res * i % MOD; }
    cout << res << endl;
    return 0;
}
