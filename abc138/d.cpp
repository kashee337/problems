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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> G(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    vector<ll> dp(n, 0);
    rep(i, q) {
        ll p, x;
        cin >> p >> x;
        p--;
        dp[p] += x;
    }
    function<void(int, int, ll)> dfs = [&](int at, int par, ll x) -> void {
        dp[at] += x;
        for (auto to : G[at]) {
            if (to == par) continue;
            dfs(to, at, dp[at]);
        }
    };
    dfs(0, -1, 0);
    for (auto v : dp) cout << v << endl;
    return 0;
}