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
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    ll n, s, k;
    vector<ll> res;
    rep(i, t) {
        cin >> n >> s >> k;
        ll g = calc_gcd(k, n);
        if (s % g != 0) {
            res.pb(-1);
        } else {
            k /= g;
            n /= g;
            s /= g;
            ll _k = modinv(k, n);
            ll _res = _k * (n - s) % n;
            res.pb(_res);
        }
    }
    for (auto r : res) { cout << r << endl; }
    return 0;
}