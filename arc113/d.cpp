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
constexpr int MOD = 998244353;

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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<mint> dp(k + 1, 0);
    // i=1 to k,j=1 to nの時、Aにおけるあり得る状態数は,nCj*(i-1)^(n-j)
    //これは普通に二項定理で解ける
    //(1+(i-1))^n=i^n
    if (n == 1 && m != 1) {
        mint val = k;
        dp[k] = val.pow(m);
    } else if (m == 1) {
        mint val = k;
        dp[k] = val.pow(n);
    } else {
        reps(x, k + 1, 1) {
            mint a1 = x;
            mint a2 = x - 1;
            mint a = a1.pow(n) - a2.pow(n);
            mint b = k - x + 1;
            b = b.pow(m);
            dp[x] += dp[x - 1] + a * b;
        }
    }
    cout << dp[k] << endl;
    return 0;
}