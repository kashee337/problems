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
    ll n, W;
    cin >> n >> W;
    vector<ll> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];

    vector<map<ll, ll>> dp(n + 1);
    set<ll> s;
    dp[0][0] = 0;
    rep(i, n) {
        for (auto a : dp[i]) {
            ll nv = min(a.first + w[i], W + 1);
            dp[i + 1][nv] = max(dp[i][nv], dp[i][a.first] + v[i]);
            dp[i + 1][a.first] = max(dp[i + 1][a.first], dp[i][a.first]);
        }
    }
    ll res = -INF;
    for (auto a : dp[n]) {
        if (a.first > W) continue;
        res = max(res, a.second);
    }
    cout << res << endl;
    return 0;
}