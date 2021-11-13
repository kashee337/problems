#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
ll calc_gcd(ll x, ll y) {
    if (y == 0) return x;
    return calc_gcd(y, x % y);
}

ll calc_lcm(ll x, ll y) { return (x / calc_gcd(y, x % y)) * y; }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    set<pair<ll, ll>> dxdy;
    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            ll dx = x[i] - x[j];
            ll dy = y[i] - y[j];
            if (dx != 0 && dy != 0) {
                ll gcd = calc_gcd(abs(dx), abs(dy));
                dx /= gcd;
                dy /= gcd;
            } else if (dx == 0) {
                dy = dy / abs(dy);
            } else {
                dx = dx / abs(dx);
            }
            dxdy.insert({dx, dy});
        }
    }
    ll res = dxdy.size();

    cout << res << endl;
    return 0;
}