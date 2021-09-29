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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> d(n + 1, 0);
    ll prev = 0;
    rep(i, n) {
        d[i] = (a[i] - 1) - prev;
        prev = a[i];
    }
    d[n] = (ll)1e18 + (ll)(n + 10);
    rep(i, n) { d[i + 1] += d[i]; }
    vector<ll> res;
    rep(i, q) {
        ll k;
        cin >> k;

        ll tmp;
        int idx = lower_bound(d.begin(), d.end(), k) - d.begin();
        if (idx == 0) {
            tmp = k;
        } else {
            tmp = a[idx - 1] + (k - d[idx - 1]);
        }
        res.pb(tmp);
    }

    for (auto r : res) cout << r << endl;
    return 0;
}
