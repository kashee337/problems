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
vector<vector<ll>> G;
vector<ll> c;
vector<ll> res;

void dfs(int from, int crr, map<int, int> used) {
    if (used[c[crr]] == 0) res.pb(crr);
    used[c[crr]]++;
    for (auto next : G[crr]) {
        if (from == next) continue;
        dfs(crr, next, used);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    c.resize(n);
    G.resize(n);
    rep(i, n) cin >> c[i];
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    map<int, int> used;

    dfs(-1, 0, used);
    sort(res.begin(), res.end());
    for (auto v : res) cout << v + 1 << endl;
    return 0;
}