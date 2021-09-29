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
class mint {
    long long x;

  public:
    mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint& a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res *= a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const { return pow(MOD - 2); }
    mint& operator/=(const mint& a) { return (*this) *= a.inv(); }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res /= a;
    }

    friend ostream& operator<<(ostream& os, const mint& m) {
        os << m.x;
        return os;
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string l, r;
    cin >> l >> r;
    ll n = l.size();
    ll m = r.size();
    mint res = 0;
    if (n != m) {
        reps(i, m + 1, n) {
            mint num, l_v, r_v;
            mint size = i;
            if (i == n) {
                l_v = stol(l);
                r_v = powl(10, i) - 1LL;
            } else if (i < m) {
                l_v = powl(10, i - 1);
                r_v = powl(10, i) - 1LL;
            } else {
                l_v = powl(10, i - 1);
                r_v = stol(r);
            }
            num = r_v - l_v + 1LL;
            res += size * num * (l_v + r_v) / 2;
        }
    } else {
        mint size = n;
        mint num = stol(r) - stol(l) + 1;
        res += size * num * (stol(r) + stol(l)) / 2;
    }

    cout << res << endl;
    return 0;
}