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

ll dp[10001][2][100];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int d;
    string n;
    cin >> d >> n;
    dp[0][0][0] = 1;
    rep(i, n.size()) {
        int v = n[i] - '0';
        rep(small, 2) {
            int r = small ? 10 : v + 1;
            rep(j, r) {
                rep(k, d) {
                    dp[i + 1][small || j < v][(k + j) % d] += dp[i][small][k];
                    dp[i + 1][small || j < v][(k + j) % d] %= MOD;
                }
            }
        }
    }
    ll res = (dp[n.size()][1][0] + dp[n.size()][0][0]) % MOD;
    cout << res - 1LL << endl;
    return 0;
}