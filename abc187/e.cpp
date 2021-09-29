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
vector<ll> c;
vector<ll> parent;
vector<vector<ll>> G;

void dfs(int v, int p) {
    parent[v] = p;
    if (p != -1) c[v] += c[p];
    for (auto nv : G[v]) {
        if (nv == p) continue;
        dfs(nv, v);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;

    c = vector<ll>(n, 0);
    vector<ll> a(n - 1), b(n - 1);
    G = vector<vector<ll>>(n, vector<ll>());
    rep(i, n - 1) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        G[a[i]].pb(b[i]);
        G[b[i]].pb(a[i]);
    }
    int root = 0;
    parent = vector<ll>(n, 0);

    dfs(root, -1);

    ll q;
    ll offset = 0;
    cin >> q;
    int t, e, x;
    rep(i, q) {
        cin >> t >> e >> x;
        e--;
        int _a = a[e], _b = b[e];
        if (t == 1) swap(_a, _b);
        if (parent[_b] == _a)
            c[_b] += x;
        else
            c[_a] -= x, offset += x;
    }
    dfs(root, -1);
    for (auto v : c) cout << v + offset << endl;
    return 0;
}