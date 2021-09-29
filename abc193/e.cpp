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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

inline ll mod(ll a, ll m) { return (a % m + m) % m; }

ll extGcd(ll a, ll b, ll& p, ll& q) {
    if (b == 0) {
        p = 1;
        q = 0;
        return a;
    }
    ll d = extGcd(b, a % b, q, p);
    q -= a / b * p;
    return d;
}

pair<ll, ll> crt(const vector<ll>& b, const vector<ll>& m) {
    ll r = 0, M = 1;
    for (int i = 0; i < (int)b.size(); ++i) {
        ll p, q;
        ll d = extGcd(M, m[i], p, q);  // p is inv of M/d (mod. m[i]/d)
        if ((b[i] - r) % d != 0) return make_pair(0, -1);
        ll tmp = (b[i] - r) / d * p % (m[i] / d);
        r += M * tmp;
        M *= m[i] / d;
    }
    return make_pair(mod(r, M), M);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(i, t) {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;

        ll m1 = 2 * (x + y);
        ll m2 = p + q;
        ll res = INF;
        reps(b1, x + y, x) {
            reps(b2, p + q, p) {
                auto tmp = ChineseRem({b1, b2}, {m1, m2});
                if (tmp.second < 0) continue;
                if (res > tmp.first) res = tmp.first;
            }
        }
        if (res == INF)
            cout << "infinity" << endl;
        else
            cout << res << endl;
    }

    return 0;
}