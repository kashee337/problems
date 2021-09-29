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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<ll> dp(n, 0);
    vector<ll> dp_cost(n, INF);
    vector<bool> used(n, false);
    queue<pair<ll, ll>> q;
    q.push({n - 1, 0});
    dp[n - 1] = 1;
    dp_cost[n - 1] = 0;
    while (!q.empty()) {
        ll crr_node = q.front().first;
        ll crr_cost = q.front().second;
        q.pop();
        if (used[crr_node]) continue;
        used[crr_node] = true;
        for (auto next_node : g[crr_node]) {
            q.push({next_node, crr_cost + 1});
            if (dp_cost[next_node] >= crr_cost + 1) {
                dp_cost[next_node] = crr_cost + 1;
                dp[next_node] = (dp[next_node] + dp[crr_node]) % MOD;
            }
        }
    }
    cout << dp[0] << endl;
    return 0;
}
