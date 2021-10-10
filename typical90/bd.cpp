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
    int n, s;
    cin >> n >> s;
    vector<ll> a(n), b(n);
    rep(i, n) { cin >> a[i] >> b[i]; }
    vector<vector<bool>> dp(n + 1, vector<bool>(s + 5, 0));
    vector<vector<string>> path(n + 1, vector<string>(s + 5));
    dp[0][0] = 1;
    rep(i, n) {
        rep(j, s + 1) {
            if (j - a[i] >= 0 && dp[i][j - a[i]]) {
                dp[i + 1][j] = true;
                path[i + 1][j] = "A";
            }
            if (j - b[i] >= 0 && dp[i][j - b[i]]) {
                dp[i + 1][j] = true;
                path[i + 1][j] = "B";
            }
        }
    }
    int crr = s;
    string res = "";
    if (dp[n][crr] == 0) {
        res = "Impossible";
    } else {
        rrep(i, n + 1) {
            res += path[i][crr];
            if (path[i][crr] == "A")
                crr -= a[i - 1];
            else
                crr -= b[i - 1];
        }
        reverse(res.begin(), res.end());
    }
    cout << res << endl;
    return 0;
}