#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>

#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n, s) for (int i = (s); i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define rreps(i, n, s) for (int i = s; i >= n; i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

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
    ll n,k;
    cin>>n>>k;

    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    
    vector<vector<mint>>dp(n+1,vector<mint>(k+1,0));
    dp[0][0]=1;
    rep(i,n){
      vector<mint> sum(k+2,0);
      rep(j,k+1){
        sum[j+1]=sum[j]+dp[i][j];
      }

      rep(j,k+1){
        ll d = max(0LL,(ll)j-a[i]);
        dp[i+1][j] = sum[j+1]-sum[d]; 
      }
    }

    cout<<dp[n][k]<<endl;
    return 0;
}