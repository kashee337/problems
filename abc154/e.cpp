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
    string n;
    cin >> n;
    int k;
    cin >> k;
    int l = n.size();
    vector<vector<vector<ll>>> dp(l + 1, vector<vector<ll>>(2, vector<ll>(100 + 1, 0)));
    dp[0][0][0] = 1;
    ll zero = 0;
    rep(i, l) {
        int c = n[i] - '0';
        if (c > 0) zero++;

        rep(small, 2) {
            if (small) {
                rep(_k, k + 1) {
                    dp[i + 1][1][_k] += dp[i][1][_k] + (c > 0) * dp[i][0][_k];
                    if (_k > 0) { dp[i + 1][1][_k] += 9 * dp[i][1][_k - 1] + max(0, (c - 1)) * dp[i][0][_k - 1]; }
                }
            } else {
                if (c == 0)
                    dp[i + 1][0][zero] += dp[i][0][zero];
                else
                    dp[i + 1][0][zero] += dp[i][0][zero - 1];
            }
        }
    }

    cout << dp[l][0][k] + dp[l][1][k] << endl;

    return 0;
}