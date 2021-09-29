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
    vector<ll> a(n), b(m);

    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    rep(i, n + 1) dp[i][0] = i;
    rep(i, m + 1) dp[0][i] = i;

    rep(i, n) {
        rep(j, m) {
            int k = 1;
            if (a[i] == b[j]) k = 0;
            dp[i + 1][j + 1] = min(min(dp[i + 1][j] + 1, dp[i][j + 1] + 1), dp[i][j] + k);
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}