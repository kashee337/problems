#include <bits/stdc++.h>

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
ll n,k;
cin>>n>>k;
vector<ll> a(n),pos_a,neg_a;

rep(i,n){
    cin>>a[i];
    if(a[i]<0){
        neg_a.pb(a[i]);
    }
    else if(a[i]>0){
        pos_a.pb(a[i]);
    }
}
int p_num = pos_a.size();
int n_num = neg_a.size();

mint ans=1;

if(k>n_num+p_num){
  //全部使う
  sort(a.begin(),a.end(),greater<ll>());
  rep(i,k){
      ans*=a[i];
  }
}
else if(p_num==0){
  //全て負なら大きい順に全部使う
  sort(neg_a.begin(),neg_a.end(),greater<ll>());
  rep(i,k){
    ans*=neg_a[i];
  }    
}
else{
  //混ざっている場合
  //絶対値で降順に並べる
  sort(pos_a.begin(),pos_a.end(),greater<ll>());
  sort(neg_a.begin(),neg_a.end());
  int p_idx=0,n_idx=0;

  //絶対値の大きい順にk個掛ける
  rep(i,k){
    if(p_idx<p_num&&n_idx<n_num){
      if(pos_a[p_idx]>abs(neg_a[n_idx])){
        ans*=pos_a[p_idx];
        p_idx++;
      }
      else{
        ans*=neg_a[n_idx];
        n_idx++;
      }
    }
    else if(n_idx==n_num){
      ans*=pos_a[p_idx];
      p_idx++;
    }
    else{
      ans*=neg_a[n_idx];
      n_idx++;
    }
  }

  //負の数を奇数個使っていた場合
  if(n_idx%2!=0){
    //正の数も負の数も1個以上余っている場合
    if(p_idx<p_num&&n_idx<n_num){
      ll tmp_neg = neg_a[n_idx-1]*neg_a[n_idx];
      ll tmp_pos = pos_a[p_idx-1]*pos_a[p_idx];

      if(tmp_neg>tmp_pos){
        ans/=pos_a[p_idx-1];
        ans*=neg_a[n_idx];
      }
      else{
        ans/=neg_a[n_idx-1];
        ans*=pos_a[p_idx];
      }

    }//正の数だけが一個以上余っている場合
    else if(n_idx==n_num){
      ans/=neg_a[n_idx-1];
      ans*=pos_a[p_idx];
    }//負の数だけが一個以上余っている場合
    else{
      ans/=pos_a[p_idx-1];
      ans*=neg_a[n_idx];
    }
  }
}

cout<<ans<<endl;
return 0;
}