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
    ll N, B, K;
    cin >> N >> B >> K;
    vector<ll> c(K);
    rep(i, K) cin >> c[i];
    vector<vector<ll>> dp(2, vector<ll>(B, 0));
    map<ll, ll> memo;
    dp[0][0] = 1;
    rep(i, N) {
        rep(j, B) {
            rep(k, K) {
                ll val = (10 * j + c[k]) % B;
                dp[1][val] += dp[0][j];
                dp[1][val] %= MOD;
            }
        }
        swap(dp[0], dp[1]);
        dp[1] = vector<ll>(B, 0);
        if (memo[dp[0]]) {
            ll shift = (N - i) % memo.size();
            ll cnt = 0;
            for (auto v : memo) {
                if (cnt == shift) { dp[0][0] = memo[] }
            }
            break;
        }
        memo[dp[0][0]] = dp;
    }
    cout << dp[0][0] << endl;
    return 0;
}
