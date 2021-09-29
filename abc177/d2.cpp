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
    vector<ll> _parents;
    vector<ll> _size;
    UnionFind(ll N) : _parents(N), _size(N, 1) { rep(i, N) _parents[i] = i; }

    ll root(ll x) {
        if (_parents[x] == x)
            return x;
        else
            return _parents[x] = root(_parents[x]);
    }

    bool unite(ll x, ll y) {
        ll rx = root(x);
        ll ry = root(y);
        if (rx == ry) return false;
        if (_size[rx] < _size[ry]) swap(rx, ry);
        if (_size[rx] == _size[ry]) { _size[rx] += 1; };
        _parents[ry] = rx;
        return true;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    UnionFind uf(n);
    ll a, b;

    rep(i, m) {
        cin >> a >> b;
        a--, b--;
        uf.unite(a, b);
    }
    map<ll, ll> group;
    ll res = 0;
    rep(i, n) {
        group[uf.root(i)]++;
        res = max(group[uf.root(i)], res);
    }
    cout << res << endl;
    return 0;
}