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
    vector<ll> a(n), t(n);
    rep(i, n) cin >> a[i] >> t[i];

    //隣り合った同一の演算を圧縮する
    vector<ll> ca0, ct0, ca1, ct1;
    rep(i, n - 1) {
        if (i < n) {
            ll c = 0;
            while (t[i] == t[i + 1] && i < n - 1) {
                if (t[i] == 1) {
                    c += a[i];
                } else if (t[i] == 2) {
                    c = max(a[i], a[i + 1]);
                } else {
                    c = min(a[i], a[i + 1]);
                }
                i++;
            }
            if (t[i] == 1) c += a[i];
            ca0.pb(c);
            ct0.pb(t[i]);
        }
    }
    if (t[n - 1] != t[n - 2]) {
        ca0.pb(a[n - 1]);
        ct0.pb(t[n - 1]);
    }
    // min-maxの関係で消せる演算は消す
    rep(i, ca0.size()) {
        if (i < ca0.size() - 1) {
            if (ct0[i] == 3 && ct0[i + 1] == 2 && ca0[i] < ca0[i + 1]) continue;
            if (ct0[i] == 2 && ct0[i + 1] == 3 && ca0[i] > ca0[i + 1]) continue;
        }
        ca1.pb(ca0[i]);
        ct1.pb(ct0[i]);
    }
    ll q;
    cin >> q;
    vector<ll> x(n);
    rep(i, q) {
        cin >> x[i];
        ll res = x[i];
        rep(i, ca1.size()) {
            if (ct1[i] == 1)
                res += ca1[i];
            else if (ct1[i] == 2)
                res = max(res, ca1[i]);
            else
                res = min(res, ca1[i]);
        }
        cout << res << endl;
    }

    return 0;
}

// 5
// 2 2
// 5 2
// 1 1
// 1 1
// 1 1