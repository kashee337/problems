#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
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

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int H,W;
cin>>H>>W;
vector<string>s(H);

rep(i,H)cin>>s[i];
vector<vector<vector<int>>>dp(H,vector<vector<int>>(W,vector<int>(4,0)));

ll k=0;
rep(y,H){
    rep(x,W){
    if(s[y][x]=='.'){
        if(x>0)dp[y][x][0]=dp[y][x-1][0];
        if(y>0)dp[y][x][1]=dp[y-1][x][1];
        dp[y][x][0]++;
        dp[y][x][1]++;

        k++;
        }
    }
}
rrep(y,H){
    rrep(x,W){
    if(s[y][x]=='.'){
        if(x<W-1)dp[y][x][2]=dp[y][x+1][2];
        if(y<H-1)dp[y][x][3]=dp[y+1][x][3];
        dp[y][x][2]++;
        dp[y][x][3]++;
        }
    }
}

mint ans=0;
rep(y,H){
    rep(x,W){
        if(s[y][x]!='.')continue;
        mint val1 = 2;
        mint val2 = 2;
        ll t = dp[y][x][0]+dp[y][x][1]+dp[y][x][2]+dp[y][x][3]-3;
        ans+=(val1.pow(t)-1)*val2.pow(k-t);
    }
}
cout<<ans<<endl;
return 0;
}