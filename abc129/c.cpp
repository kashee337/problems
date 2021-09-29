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
    ll n, m;
    cin >> n >> m;
    vector<bool> broken(n + 1, false);
    rep(i, m) {
        int a;
        cin >> a;
        broken[a] = true;
    }
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    rep(i, n + 1) {
        reps(j, i + 3, i + 1) {
            if (j > n) continue;
            if (broken[j]) continue;
            dp[j] = (dp[j] + dp[i]) % MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}