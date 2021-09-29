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
template <typename T>
T calc_gcd(T x, T y) {
  if (y == 0) return x;
  return calc_gcd(y, x % y);
}

template <typename T>
T calc_lcm(T x, T y) { return (x / calc_gcd(y, x % y)) * y; }

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int n,m;
cin>>n>>m;
string s,t;
cin>>s>>t;
ll num=calc_lcm(s.size(),t.size());
map<int,char> x;
rep(i,n){
    int idx=1+i*(num/n);
    x[idx]=s[i];
}
rep(i,m){
    int idx=1+i*(num/m);
    if(x.count(idx)&&x[idx]!=t[i]){
        num=-1;
        break;
    }
    x[idx]=t[i];
}
cout<<num<<endl;
return 0;
}