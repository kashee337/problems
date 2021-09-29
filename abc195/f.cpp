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
};
map<ll, ll> prime_factorize(ll N) {
    map<ll, ll> res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;  // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        res[a]++;
    }

    // 最後に残った数について
    if (N != 1) res[N]++;
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b;
    cin >> a >> b;
    ll n = b - a + 1;
    ll res = 0;
    vector<map<ll, ll>> factors;
    for (ll i = a; i <= b; i++) { factors.pb(prime_factorize(i)); }
    UnionFind<ll> uf(n);
    rep(i, n) {
        reps(j, n, i + 1) {
            for (auto f : factors[i]) {
                if (factors[j].count(f.first)) { uf.unite(i, j); }
            }
        }
    }
    map<int, int> group;
    rep(i, n) { group[uf.root(i)]++; }
    ll res = 0;
    reps(k, n + 1, 2) {
        vector<bool> used(n, false);
        vector<vector<ll>> indices_list;

        rep(i, n){vector<ll>}

        ll tmp = 1;
        for (auto indices : indices_list) {
            for (auto idx : indices) { tmp *= group[idx]; }
        }
        res += tmp;
    }
    cout << res << endl;
    return 0;
}