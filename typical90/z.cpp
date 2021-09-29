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
vector<ll> green, red;
vector<vector<ll>> g;

void dfs(int from, int crr, int c) {
    if (c == 0)
        green.pb(crr);
    else
        red.pb(crr);

    for (auto to : g[crr]) {
        if (to == from) continue;
        dfs(crr, to, (c + 1) % 2);
    }
    return;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    g.resize(n);
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(-1, 0, 0);
    if (green.size() >= n / 2) {
        rep(i, n / 2) { cout << green[i] + 1 << endl; }
    } else {
        rep(i, n / 2) { cout << red[i] + 1 << endl; }
    }
    return 0;
}