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
    ll n, C;
    cin >> n >> C;
    vector<vector<ll>> dp(C + 1, vector<ll>(ll(1e5) + 10LL, 0));
    rep(i, n) {
        ll s, t, c;
        cin >> s >> t >> c;
        s--, t--, c--;
        dp[c][s]++;
        dp[c][t + 1]--;
    }

    rep(i, ll(1e5) + (ll)10) {
        rep(c, C) { dp[c][i + 1] += dp[c][i]; }
    }
    rep(i, ll(1e5) + (ll)10) {
        rep(c, C) {
            if (dp[c][i]) dp[c][i] = 1;
        }
    }
    ll res = -1;
    rep(i, ll(1e5) + (ll)10) {
        ll cnt = 0;
        rep(c, C) { cnt += dp[c][i]; }
        res = max(res, cnt);
    }
    cout << res << endl;
    return 0;
}