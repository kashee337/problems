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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(200));

    vector<int> d;
    d.pb(-1);
    dp[0][0] = d;
    map<ll, vector<vector<int>>> memo;

    rep(i, n) {
        rep(k, 200) {
            if (dp[i][k].size() == 0) continue;

            ll v = (k + a[i]) % 200;
            dp[i + 1][k] = dp[i][k];
            vector<int> tmp = dp[i][k];

            tmp.pb(i);
            dp[i + 1][v] = tmp;
            memo[v].pb(tmp);
        }
    }

    for (auto v : memo) {
        if (v.second.size() >= 2) {
            cout << "Yes" << endl;
            cout << v.second[0].size() - 1 << " ";
            for (auto m : v.second[0]) {
                if (m > -1) cout << m + 1 << " ";
            }
            cout << endl;
            cout << v.second[1].size() - 1 << " ";
            for (auto m : v.second[1]) {
                if (m > -1) cout << m + 1 << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
