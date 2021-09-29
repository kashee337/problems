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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> ab(m);
    rep(i, m) {
        cin >> ab[i].first >> ab[i].second;
        ab[i].first--, ab[i].second--;
    }

    vector<ll> res;
    ll crr = (n * (n - 1)) / 2;

    res.pb(crr);
    UnionFind uf(n);
    rrep(i, m) {
        ll a = ab[i].first;
        ll b = ab[i].second;
        if (!uf.issame(a, b)) {
            ll len_a = uf.size(a);
            ll len_b = uf.size(b);
            crr -= len_a * len_b;
        }
        uf.merge(a, b);
        res.pb(crr);
    }
    reverse(res.begin(), res.end());
    rep(i, m) cout << res[i + 1] << endl;
    return 0;
}