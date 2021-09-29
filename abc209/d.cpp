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
vector<vector<ll>> g;
vector<ll> depth;
void dfs(ll crr, ll d) {
    depth[crr] = d;
    for (auto next : g[crr]) {
        if (depth[next] > -1) continue;
        dfs(next, d + 1);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    g.resize(n);
    rep(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    depth.assign(n, -1);
    dfs(0, 0);
    rep(i, q) {
        ll c, d;
        cin >> c >> d;
        c--, d--;
        if (abs(depth[c] - depth[d]) % 2 == 0) {
            cout << "Town" << endl;
        } else {
            cout << "Road" << endl;
        }
    }
    return 0;
}
