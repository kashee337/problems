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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    map<ll, ll> memo;
    memo[x] = 0;
    memo[0] = INF;
    for (int i = n - 1; i >= 0; i--) {
        for (auto it : memo) {
            ll _x = it.first;
            ll m = it.second;
            if (_x % a[i] == 0) {
                memo[0] = min(memo[0], m + _x / a[i]);
                continue;
            }
            ll k1 = _x / a[i];
            ll k2 = (_x / a[i]) + 1;
            ll v1 = abs(_x - k1 * a[i]);
            ll v2 = abs(_x - k2 * a[i]);
            if (memo.count(v1)) {
                memo[v1] = min(m + k1, memo[v1]);
            } else {
                memo[v1] = m + k1;
            }
            if (memo.count(v2)) {
                memo[v2] = min(m + k2, memo[v2]);
            } else {
                memo[v2] = m + k2;
            }
        }
    }

    cout << memo[0] << endl;
    return 0;
}
// ll crr = i;
// ll cnt;
// for (auto v : memo)
//     if (x % a[i] == 0) {
//         cnt = x / a[i];
//     } else {
//         cnt = x / a[i] + 1;
//     }
// ll y_x = cnt * a[i] - x;
// crr--;
// if (memo.count(y_x)) { memo[y_x] = min(crr, memo[y_x]); }

// while (y_x > 0) {
//     cnt += y_x / a[crr];
//     y_x %= a[crr];
//     crr--;
// }
// res = min(res, cnt);
