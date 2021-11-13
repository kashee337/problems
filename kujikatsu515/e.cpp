#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
    vector<pair<ll, ll>> xc(n);
    map<ll, pair<ll, ll>> d;
    rep(i, n) {
        cin >> xc[i].first >> xc[i].second;
        d[xc[i].second] = {INF, -INF};
    }
    rep(i, n) {
        int v = xc[i].second;
        d[v].first = min(d[v].first, xc[i].first);
        d[v].second = max(d[v].second, xc[i].first);
    }
    sort(xc.begin(), xc.end());
    int cnt = 1;
    map<int, int> pos;
    rep(i, n) pos[xc[i].first] = cnt++;
    vector<ll> dp(n + 1, INF);
    dp[0] = 0;
    ll prev_xmin = 0, prev_xmax = 0;
    ll prev_xmin_idx = 0, prev_xmax_idx = 0;
    for (auto k : d) {
        ll xmin = k.second.first, xmax = k.second.second;
        ll xmin_idx = pos[xmin], xmax_idx = pos[xmax];

        dp[xmin_idx] = min(dp[xmin_idx], dp[prev_xmin_idx] + abs(xmin - xmax) + abs(xmax - prev_xmin));
        dp[xmin_idx] = min(dp[xmin_idx], dp[prev_xmax_idx] + abs(xmin - xmax) + abs(xmax - prev_xmax));

        dp[xmax_idx] = min(dp[xmax_idx], dp[prev_xmin_idx] + abs(xmin - xmax) + abs(xmin - prev_xmin));
        dp[xmax_idx] = min(dp[xmax_idx], dp[prev_xmax_idx] + abs(xmin - xmax) + abs(xmin - prev_xmax));

        prev_xmin = xmin;
        prev_xmax = xmax;
        prev_xmin_idx = xmin_idx;
        prev_xmax_idx = xmax_idx;
    }
    ll res = min(dp[prev_xmin_idx] + abs(prev_xmin), dp[prev_xmax_idx] + abs(prev_xmax));
    cout << res << endl;
    return 0;
}