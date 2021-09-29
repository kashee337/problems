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
    cin >> n;
    vector<vector<ll>> dp(1005, vector<ll>(1005, 0));
    rep(i, n) {
        ll lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        dp[ly][lx] += 1;
        dp[ry][lx] -= 1;
        dp[ly][rx] -= 1;
        dp[ry][rx] += 1;
    }
    rep(x, 1001) {
        rep(y, 1001) { dp[y][x + 1] += dp[y][x]; }
    }
    rep(y, 1001) {
        rep(x, 1001) { dp[y + 1][x] += dp[y][x]; }
    }
    map<ll, ll> res;
    rep(x, 1001) {
        rep(y, 1001) { res[dp[y][x]]++; }
    }
    reps(k, n + 1, 1) { cout << res[k] << endl; }
    return 0;
}