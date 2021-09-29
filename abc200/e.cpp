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
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(4, vector<ll>(n * 3 + 5));
    dp[0][0] = 1;
    rep(i, 3) {
        rep(j, i * n + 1) {
            dp[i + 1][j + 1] += dp[i][j];
            dp[i + 1][j + n + 1] -= dp[i][j];
        }

        rep(j, 3 * n + 1) { dp[i + 1][j + 1] += dp[i + 1][j]; }
    }
    ll x;
    rep(i, 3 * n + 1) {
        if (k <= dp[3][i]) {
            x = i;
            break;
        } else {
            k -= dp[3][i];
        }
    }
    reps(i, n + 1, 1) {
        ll jmi = max((ll)1, x - i - n);
        ll jma = min(n, x - i - 1);
        if (jmi > jma) continue;
        if (k > jma - jmi + 1) {
            k -= (jma - jmi + 1);
            continue;
        }
        ll j = jmi + k - 1;
        ll k = x - i - j;
        cout << i << " " << j << " " << k << endl;
        return 0;
    }
    return 0;
}