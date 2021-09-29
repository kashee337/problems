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
    ll gcd_a = 0, gcd_b = 0;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        ll tmp_a1 = calc_gcd(a, gcd_a);
        ll tmp_b1 = calc_gcd(b, gcd_b);
        ll lcm_1 = calc_lcm(tmp_a1, tmp_b1);

        ll tmp_a2 = calc_gcd(b, gcd_a);
        ll tmp_b2 = calc_gcd(a, gcd_b);
        ll lcm_2 = calc_lcm(tmp_a2, tmp_b2);

        if (lcm_1 >= lcm_2) {
            gcd_a = tmp_a1;
            gcd_b = tmp_b1;
        } else {
            gcd_a = tmp_a2;
            gcd_b = tmp_b2;
        }
    }

    ll res = calc_lcm(gcd_a, gcd_b);

    cout << res << endl;
    return 0;
}