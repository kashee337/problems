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
constexpr long long MAX = 200005;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> t(n);
    rep(i, n) cin >> t[i];
    sort(t.begin(), t.end());
    vector<vector<bool>> dp(n + 1, vector<bool>(MAX, false));
    dp[0][0] = true;
    rep(i, n) {
        rep(v, 100005) {
            if (dp[i][v]) {
                dp[i + 1][v] = true;
                dp[i + 1][v + t[i]] = true;
            }
        }
    }
    ll res = INF;
    ll sum = 0;
    rep(i, n) sum += t[i];
    rep(v, 100005) {
        if (dp[n][v]) { res = min(max(sum - (ll)v, (ll)v), res); }
    }
    cout << res << endl;
    return 0;
}