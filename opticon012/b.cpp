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
    vector<ll> a(n), b(n);
    ll sum_a = 0;
    rep(i, n) {
        cin >> a[i];
        sum_a += a[i];
    }
    rep(i, n) cin >> b[i];
    ll v = 0;
    ll res = 0;
    rep(i, n) {
        if (a[i] < b[i]) {
            v -= abs(a[i] - b[i]);
            a[i] = b[i];
            res++;
        }
    }
    vector<ll> diff;
    rep(i, n) {
        if (a[i] > b[i]) { diff.pb(abs(a[i] - b[i])); }
    }
    sort(diff.begin(), diff.end(), greater<ll>());
    for (auto d : diff) {
        if (v < 0) {
            v += d;
            res++;
        }
    }
    if (v >= 0)
        cout << res << endl;
    else
        cout << -1 << endl;
    return 0;
}