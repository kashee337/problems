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
    string s;
    ll k;
    cin >> s >> k;
    ll n = s.size();
    vector<vector<vector<map<ll, ll>>>> dp(n + 1, vector<vector<map<ll, ll>>>(2, vector<map<ll, ll>>(2)));
    dp[0][0][1][1] = 1;
    rep(i, n) {
        rep(smaller, 2) {
            rep(zero, 2) {
                for (auto p : dp[i][smaller][zero]) {
                    ll v = p.first;
                    ll num = p.second;
                    int cur = s[i] - '0';
                    rep(d, 10) {
                        if (smaller == 0 && cur < d) continue;
                    }
                }
            }
        }
    }
    ll res = 0;
    rep(d, k + 1) res += dp[n][1][d] + dp[n][0][d];
    return 0;
}