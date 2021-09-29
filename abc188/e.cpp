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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<ll>> node(n);

    rep(i, m) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        node[x].push_back(y);
    }

    vector<bool> visit(n, false);

    vector<ll> dp(n, INF);
    rep(now, n) {
        if (visit[now]) continue;
        visit[now] = true;

        for (auto next : node[now]) { dp[next] = min(dp[next], min(dp[now], a[now])); }
    }

    ll res = -INF;
    rep(i, n) {
        if (dp[i] == INF) continue;
        res = max(a[i] - dp[i], res);
    }
    cout << res << endl;
    return 0;
}