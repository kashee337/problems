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
    int t;
    cin >> t;
    string tmp = "atcoder";
    // cout << ("atcoder" < "atcoderr") << endl;
    rep(i, t) {
        string s;
        cin >> s;
        // if(s.substr(0,tmp.size())==tmp&&)
        vector<ll> dp(tmp.size(), -1);
        ll res = INF;
        rep(j, tmp.size()) {
            rep(k, s.size()) {
                if (tmp[j] < s[k]) {
                    dp[j] = k;
                    res = min(res, (ll)k);
                    break;
                }
            }
            if (j < s.size() && tmp[j] != s[j] && dp[j] == -1) break;
        }
        if (res == INF) res = -1;
        cout << res << endl;
    }

    return 0;
}