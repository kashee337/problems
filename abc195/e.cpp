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
    ll n;
    string _s, _x;
    cin >> n >> _s >> _x;
    vector<ll> s(n), x(n);
    rep(i, n) {
        s[i] = _s[i] - '0';
        x[i] = _x[i] == 'T' ? 0 : 1;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(7, 0));
    reps(i, 7, 1) dp[n][i] = 1;

    rrep(i, n) {
        rep(r, 7) {
            //余りがrの時に取れるアクションを取った時に勝ちの形があるか？無ければ必敗として相手のマークをつける。
            if (dp[i + 1][(10 * r + s[i]) % 7] == x[i] || dp[i + 1][10 * r % 7] == x[i]) {
                dp[i][r] = x[i];
            } else {
                dp[i][r] = 1 - x[i];
            }
        }
    }
    if (dp[0][0] == 0)
        cout << "Takahashi" << endl;
    else
        cout << "Aoki" << endl;
    return 0;
}