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
    vector<ll> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll res = 0;
    ll crr_b = 0, crr_c = 0;
    rep(i, n) {
        ll idx_b = upper_bound(b.begin() + crr_b, b.end(), a[i]) - b.begin();
        if (idx_b >= n) break;
        crr_b = idx_b + 1;
        ll idx_c = upper_bound(c.begin() + crr_c, c.end(), b[idx_b]) - c.begin();
        if (idx_c >= n) break;
        crr_c = idx_c + 1;
        res++;
    }
    cout << res << endl;
    return 0;
}