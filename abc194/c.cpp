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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> s(n + 1, 0), a2(n, 0);
    rep(i, n) {
        s[i + 1] = s[i] + a[i];
        a2[i] = a[i] * a[i];
    }
    ll res = 0;
    rep(i, n) {
        ll val_1 = 0, val_2 = 0;
        if (i < n - 1) { val_1 = -2 * a[i] * (s[n] - s[i + 1]); }
        val_2 = (n - 1) * a[i] * a[i];
        res += val_1 + val_2;
    }
    cout << res << endl;
    return 0;
}