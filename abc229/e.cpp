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
    vector<vector<ll>> g(n);
    vector<pair<ll, pair<ll, ll>>> ab(m);
    rep(i, m) {
        cin >> ab[i].second.first >> ab[i].second.second;
        ab[i].second.first--, ab[i].second.second--;
        ab[i].first = min(ab[i].second.first, ab[i].second.second);
    }
    sort(ab.begin(), ab.end(), greater<pair<ll, pair<ll, ll>>>());
    UnionFind uf(n);
    ll crr = 0;
    ll d = 0;
    vector<ll> res;
    res.pb(0);
    for (int v = n - 1; v > 0; v--) {
        while (crr < m && ab[crr].first >= v) {
            ll a = ab[crr].second.first, b = ab[crr].second.second;
            if (!uf.issame(a, b)) d++;
            uf.merge(a, b);
            crr++;
        }
        ll group = n - v - d;
        res.pb(group);
    }
    reverse(res.begin(), res.end());
    for (auto v : res) cout << v << endl;
    return 0;
}