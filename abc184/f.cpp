#include <algorithm>
#include <cmath>
#include <deque>
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
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    int ln = n / 2;
    int rn = n - n / 2;
    vector<ll> A, B;
    rep(i, 1 << ln) {
        ll v = 0;
        rep(j, ln) {
            if ((i >> j) & 1) { v += a[j]; }
        }
        A.pb(v);
    }
    rep(i, 1 << rn) {
        ll v = 0;
        rep(j, rn) {
            if ((i >> j) & 1) { v += a[ln + j]; }
        }
        B.pb(v);
    }
    sort(B.begin(), B.end());
    ll res = -1;
    for (auto vl : A) {
        ll v = 0;
        if (vl <= t) {
            auto it = lower_bound(B.begin(), B.end(), t - vl);
            int idx = distance(B.begin(), it);
            if (B[idx] == t - vl) {
                res = t;
                break;
            }
            if (idx == 0) {
                v = vl;
            } else {
                v = vl + B[idx - 1];
            }
        }
        res = max(res, v);
    }
    cout << res << endl;
    return 0;
}