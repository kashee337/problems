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

using ll = long long;
using namespace std;
constexpr long long INF = 1LL << 60;
constexpr int MAX_N = 17;

ll dp[(1 << MAX_N)][MAX_N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> x(n), y(n), z(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];
    // calc cost
    vector<vector<ll>> cost(n, vector<ll>(n, 0));
    rep(i, n) {
        reps(j, n, i + 1) {
            ll c = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            cost[i][j] = c + max(0LL, z[j] - z[i]);
            cost[j][i] = c + max(0LL, z[i] - z[j]);
        }
    }

    // TSP
    fill(dp[0], dp[(1 << MAX_N)], INF);
    dp[0][0] = 0;
    reps(S, 1 << n, 1) {
        rep(v, n) {
            if ((S >> v) & 1) {
                rep(j, n) {
                    ll S_hat = S - (1 << v);
                    if (S_hat >> j & 1 || S_hat == 0) { dp[S][v] = min(dp[S][v], dp[S_hat][j] + cost[j][v]); }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][0] << endl;
    return 0;
}