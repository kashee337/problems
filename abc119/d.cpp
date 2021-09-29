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
    ll a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b), x(q);
    rep(i, a) cin >> s[i];
    rep(i, b) cin >> t[i];
    rep(i, q) cin >> x[i];
    for (ll crr_x : x) {
        ll s_idx = lower_bound(s.begin(), s.end(), crr_x) - s.begin();
        ll t_idx = lower_bound(t.begin(), t.end(), crr_x) - t.begin();
        int sts[2] = {-1, 0};
        ll res = INF;
        rep(i, 2) {
            rep(j, 2) {
                ll s_i = s_idx + sts[i];
                ll t_i = t_idx + sts[j];
                if (s_i < 0 || s_i >= a || t_i < 0 || t_i >= b) continue;
                ll ds = crr_x - s[s_i], dt = crr_x - t[t_i];
                ll dist = min(abs(ds), abs(dt)) + abs(s[s_i] - t[t_i]);
                res = min(res, dist);
            }
        }
        cout << res << endl;
    }
    return 0;
}