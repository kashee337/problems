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
    ll m = n.size();
    vector<vector<vector<ll>>> dp(m + 1, vector<vector<ll>>(2, vector<ll>(2, 0)));
    dp[0][0][1] = 1;
    rep(i, m) {
        rep(j, 2) { dp[i + 1][1][0] += dp[i][][]; }
    }
    cout << dp[m][1][1] + dp[m][1][0] << endl;
    return 0;
}