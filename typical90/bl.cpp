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
int sign(ll v) { return v < 0 ? -1 : 1; }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> diff(n - 1);
    ll sum = 0;

    rep(i, n - 1) {
        diff[i] = a[i + 1] - a[i];
        sum += abs(diff[i]);
    }
    vector<ll> res;
    rep(i, q) {
        ll l, r, v;
        cin >> l >> r >> v;
        l--, r--;
        if (l > 0) {
            sum -= abs(diff[l - 1]);
            diff[l - 1] += v;
            sum += abs(diff[l - 1]);
        }
        if (r < n - 1) {
            sum -= abs(diff[r]);
            diff[r] -= v;
            sum += abs(diff[r]);
        }
        res.pb(sum);
    }
    for (auto sum : res) cout << sum << endl;

    return 0;
}