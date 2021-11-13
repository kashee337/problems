#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
    ll n;
    cin >> n;
    ll x, y;
    cin >> x >> y;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(y + 1, vector<ll>(x + 1, INF)));
    dp[0][0][0] = 0;
    rep(i, n) {
        rep(_x, x + 1) {
            rep(_y, y + 1) {
                ll nx = _x + a[i], ny = _y + b[i];
                nx = min(nx, x);
                ny = min(ny, y);
                dp[i + 1][ny][nx] = min(dp[i + 1][ny][nx], dp[i][_y][_x] + 1);
                dp[i + 1][_y][_x] = min(dp[i + 1][_y][_x], dp[i][_y][_x]);
            }
        }
    }
    ll res = dp[n][y][x];
    cout << (res >= INF ? -1 : res) << endl;
    return 0;
}