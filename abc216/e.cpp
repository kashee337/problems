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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) { cin >> a[i]; }
    ll res = 0;

    sort(a.begin(), a.end(), greater<ll>());
    a.pb(0);
    ll crr = 0;
    rep(i, n) {
        if (a[i] == a[i + 1]) continue;
        ll m = a[i] - a[i + 1];

        if (crr + m * (i + 1) > k) {
            ll d1 = (k - crr) / (i + 1);
            ll d2 = (k - crr) % (i + 1);
            ll l = a[i];
            ll r = a[i] - d1 + 1;
            res += (i + 1) * (l + r) * d1 / 2;
            res += (r - 1) * d2;
            crr += (i + 1) * d1 + d2;
        } else {
            ll l = a[i];
            ll r = a[i + 1] + 1;
            res += ((i + 1) * (l + r) * m) / 2;
            crr += (i + 1) * m;
        }

        if (crr >= k) break;
    }

    cout << res << endl;
    return 0;
}