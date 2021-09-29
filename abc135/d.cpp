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
    string s;
    cin >> s;
    ll n = s.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(13, 0));
    dp[0][0] = 1;
    rep(i, n) {
        rep(j, 13) {
            if (s[i] == '?') {
                rep(k, 10) {
                    dp[i + 1][(j * 10 + k) % 13] += dp[i][j];
                    dp[i + 1][(j * 10 + k) % 13] %= MOD;
                }
            } else {
                ll x = s[i] - '0';
                dp[i + 1][(j * 10 + x) % 13] += dp[i][j];
                dp[i + 1][(j * 10 + x) % 13] %= MOD;
            }
        }
    }
    cout << dp[n][5] << endl;
    return 0;
}