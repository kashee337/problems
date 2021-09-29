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

vector<vector<ll>> dp;

string dfs(ll a, ll b, ll k) {
    string s = "";
    if (a == 0) {
        rep(i, b) s += "b";
    } else if (b == 0) {
        rep(i, a) s += "a";
    } else {
        ll aCb = comb(a - 1 + b, b);
        if (aCb >= k) {
            s = "a" + dfs(a - 1, b, k);
        } else {
            s += "b" + dfs(a, b - 1, k - aCb);
        }
    }
    return s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b, k;
    cin >> a >> b >> k;
    dp = vector<vector<ll>>(a + 1, vector<ll>(b + 1, 0));
    //文字列aがi個、文字列bがj個で作られる数の個数をまず数えておく。
    dp[0][0] = 1;
    rep(i, a + 1) {
        rep(j, b + 1) {
            if (i > 0) { dp[i][j] += dp[i - 1][j]; }
            if (j > 0) { dp[i][j] += dp[i][j - 1]; }
        }
    }
    cout << dfs(a, b, k) << endl;
    return 0;
}
