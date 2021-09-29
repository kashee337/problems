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
    ll n, k, p;
    cin >> n >> k >> p;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<ll>> dp_l(k + 1), dp_r(k + 1);

    dp_l[0].pb(0);
    dp_r[0].pb(0);
    ll nl = n / 2, nr = n - nl;
    ll all_l = 1 << nl, all_r = 1 << nr;

    reps(i, all_l, 1) {
        ll crr = 0;
        ll val = 0;
        rep(bit, nl) {
            if (i >> bit & 1) {
                val += a[bit];
                crr++;
            }
        }
        if (crr > k) continue;
        dp_l[crr].pb(val);
    }
    reps(i, all_r, 1) {
        ll crr = 0;
        ll val = 0;
        rep(bit, nr) {
            if (i >> bit & 1) {
                val += a[bit + nl];
                crr++;
            }
        }
        if (crr > k) continue;
        dp_r[crr].pb(val);
    }
    rep(i, k + 1) {
        sort(dp_l[i].begin(), dp_l[i].end());
        sort(dp_r[i].begin(), dp_r[i].end());
    }
    ll res = 0;
    rep(i, k + 1) {
        for (ll vl : dp_l[i]) {
            ll num = upper_bound(dp_r[k - i].begin(), dp_r[k - i].end(), p - vl) - dp_r[k - i].begin();
            res += num;
        }
    }
    cout << res << endl;

    return 0;
}