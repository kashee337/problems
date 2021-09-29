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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<vector<vector<ll>>> dp(4, vector<vector<ll>>(h, vector<ll>(w, 0)));

    rep(i, h) {
        rep(j, w) {
            if (s[i][j] == '#') continue;
            if (i - 1 >= 0) dp[0][i][j] += dp[0][i - 1][j];
            if (j - 1 >= 0) dp[1][i][j] += dp[1][i][j - 1];
            rep(k, 2) dp[k][i][j] += 1;
        }
    }
    rrep(i, h) {
        rrep(j, w) {
            if (s[i][j] == '#') continue;
            if (i + 1 < h) dp[2][i][j] += dp[2][i + 1][j];
            if (j + 1 < w) dp[3][i][j] += dp[3][i][j + 1];
            reps(k, 4, 2) dp[k][i][j] += 1;
        }
    }
    ll res = 0;
    rep(i, h) {
        rep(j, w) { res = max(res, dp[0][i][j] + dp[1][i][j] + dp[2][i][j] + dp[3][i][j] - 3); }
    }
    cout << res << endl;
    return 0;
}