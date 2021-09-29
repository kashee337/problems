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
  vector<int>p(n);
  rep(i,n)cin>>p[i];
  vector<vector<bool>>dp(n+1,vector<bool>(10001,false));
  dp[0][0]=true;
  rep(i,n){
      rep(w,10001){
        if(dp[i][w]){
            dp[i+1][w+p[i]]=true;
            dp[i+1][w]=true;
        }
      }
  }
  int res=0;
  rep(w,10001){
      res+=dp[n][w];
  }
  cout<<res<<endl;
  return 0;
}