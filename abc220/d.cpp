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
constexpr int MOD = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll>(10, 0));
    dp[0][a[0]] = 1;
    rep(i, n - 1) {
        rep(j, 10) {
            if (dp[i][j] > 0) {
                int idx_1 = (j + a[i + 1]) % 10;
                int idx_2 = (j * a[i + 1]) % 10;
                dp[i + 1][idx_1] += dp[i][j];
                dp[i + 1][idx_1] %= MOD;
                dp[i + 1][idx_2] += dp[i][j];
                dp[i + 1][idx_2] %= MOD;
            }
        }
    }
    rep(k, 10) { cout << dp[n - 1][k] << endl; }
    return 0;
}