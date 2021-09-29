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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    int max_bit = 4;
    vector<ll> a_bits(max_bit, 0);
    rep(i, max_bit) {
        rep(j, n) { a_bits[i] += (a[j] >> i) & 1; }
    }
    vector<ll> k_bit(max_bit, 0);
    ll mlb = 0;
    rep(i, max_bit) {
        k_bit[i] += (k >> i) & 1;
        if ((k >> i) & 1) { mlb = i; }
    }
    vector<vector<vector<ll>>> dp(max_bit + 1, vector<vector<ll>>(2, vector<ll>(2, 0)));
    rrep(i, mlb) {
        if (k_bit[i]) {
            dp[i][1][0] = a_bits[i] + max(dp[i + 1][1][0], dp[i + 1][1][1]);
            dp[i][1][0] = max(dp[i + 1][1][0], a_bits[i] + max(dp[i + 1][0][0], dp[i + 1][0][1]));
            dp[i][1][1] = n - a_bits[i] + max(dp[i + 1][1][0], dp[i + 1][1][1]);
            dp[i][0][1] = n - a_bits[i] + max(dp[i + 1][0][0], dp[i + 1][0][1]);
        } else {
            dp[i][1][0] = a_bits[i] + max(dp[i + 1][1][0], dp[i + 1][1][1]);
            dp[i][1][1] = n - a_bits[i] + max(dp[i + 1][1][0], dp[i + 1][1][1]);
            dp[i][0][0] = a_bits[i] + max(dp[i + 1][0][0], dp[i + 1][0][1]);
        }
    }
    // cout<<dp[max_bit][0][0]
    return 0;
}