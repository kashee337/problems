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
vector<ll> child;
vector<vector<ll>> g;
vector<ll> dp;
ll n, k;

void dfs(int from, int crr, int depth) {
    if (depth == 0)
        dp[crr] = k;
    else if (depth == 1) {
        dp[crr] = max(0LL, k - 1 - child[from]);
        child[from]++;
    } else {
        dp[crr] = max(0LL, k - 2 - child[from]);
        child[from]++;
    }
    for (int to : g[crr]) {
        if (to == from) continue;
        dfs(crr, to, depth + 1);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    g.resize(n);
    child.assign(n, 0);
    dp.assign(n, 0);

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(-1, 0, 0);
    ll res = 1;
    for (ll v : dp) res = res * v % MOD;
    cout << res << endl;
    return 0;
}