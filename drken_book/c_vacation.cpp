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
  vector<int>a(n),b(n),c(n);
  rep(i,n)cin>>a[i]>>b[i]>>c[i];
  vector<vector<int>>dp(n+1,vector<int>(3,0));
  rep(i,n){
      dp[i+1][0] = max(dp[i][1]+a[i],dp[i][2]+a[i]);
      dp[i+1][1] = max(dp[i][0]+b[i],dp[i][2]+b[i]);
      dp[i+1][2] = max(dp[i][0]+c[i],dp[i][1]+c[i]);
  }
  cout<<max(max(dp[n][0],dp[n][1]),dp[n][2])<<endl;
  return 0;
}