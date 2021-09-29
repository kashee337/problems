#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>
#include <iomanip>

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
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<double>p(n);
  rep(i,n)cin>>p[i];
  //i枚めまで振った時にj枚表の確率
  vector<vector<double>>dp(n+1,vector<double>(n+1,0));
  dp[0][0]=1;
  rep(i,n){
      rep(j,i+1){
        dp[i+1][j+1]=dp[i][j]*p[i]+dp[i][j+1]*(1-p[i]);
        dp[i+1][j]=dp[i][j]*(1-p[i]);
        if(j>0)dp[i+1][j]+=dp[i][j-1]*p[i];
      }
  }
  double res=0;
  reps(i,n+1,(n+1)/2){
      res+=dp[n][i];
  }
  cout<<fixed<<setprecision(10)<<res<<endl;
  return 0;
}