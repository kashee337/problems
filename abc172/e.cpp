#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n, s) for (int i = (s); i < (n); i++)

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

ll nCk(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll nPk(ll n, ll k) {
  if (n == 0 || k == 0) return 1;
  return fac[n] * finv[n - k] % MOD;
}

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
  ll n, m;
  cin >> n >> m;

  COMinit();
  // nCk*mPk*(m-kPn-k)^2
  mint ans = 0;
  rep(k, n + 1) {
    mint now = nPk(m - k, n - k);
    now *= now;
    now *= nPk(m, k);
    now *= nCk(n, k);
    if (k % 2 != 0) now = -now;
    ans += now;
  }
  cout << ans << endl;
  return 0;
}