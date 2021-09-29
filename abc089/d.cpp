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
    int h, w, d;
    cin >> h >> w >> d;
    map<int, pair<int, int>> a;
    rep(y, h) rep(x, w) {
        int _a;
        cin >> _a;
        a[_a] = {x + 1, y + 1};
    }
    vector<vector<ll>> dp(h * w + 1);
    vector<bool> used(h * w + 1, false);
    reps(from, h * w + 1 - d, 1) {
        ll cost = 0;
        ll crr = from;
        dp[from].pb(0);
        if (used[crr]) continue;
        while (crr <= h * w - d) {
            ll to = crr + d;
            cost += abs(a[crr].first - a[to].first) + abs(a[crr].second - a[to].second);
            dp[from].pb(cost);
            used[crr] = true;
            crr = to;
        }
    }
    int q;
    cin >> q;
    rep(i, q) {
        int r, l;
        cin >> l >> r;
        if (l == r)
            cout << 0 << endl;
        else {
            int _o = l % d;
            if (_o == 0) _o = d;
            int _l = (l - _o) / d;
            int _r = (r - _o) / d;
            cout << dp[_o][_r] - dp[_o][_l] << endl;
        }
    }
    return 0;
}