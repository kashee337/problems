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
    ll h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    vector<vector<vector<ll>>> dp(h, vector<vector<ll>>(w, vector<ll>(2, -INF)));
    dp[h - 1][w - 1][0] = 0;
    dp[h - 1][w - 1][1] = 0;
    int dx[2] = {-1, 0}, dy[2] = {0, -1};
    int isTakahashi = 1;

    rrep(y, h) {
        rrep(x, w) {
            rep(k, 2) {
                if ((x + y) % 2 == 0)
                    isTakahashi = 0;
                else
                    isTakahashi = 1;
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || ny < 0) continue;
                ll val;
                if (a[y][x] == '+')
                    val = 1;
                else
                    val = -1;
                dp[ny][nx][isTakahashi] = max(dp[ny][nx][isTakahashi], val - dp[y][x][1 - isTakahashi]);
            }
        }
    }
    if (dp[0][0][1] > 0) {
        cout << "Takahashi" << endl;
    } else if (dp[0][0][1] < 0) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }
    return 0;
}