#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <set>
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

vector<int>dp;
vector<vector<int>>node;
int dfs(int now,int len){
    if(dp[now]!=-1)return dp[now]+len;
    int max_len=len;
    for(auto next:node[now]){
        max_len = max(dfs(next,len+1),max_len);
    }
    dp[now]=max_len-len;
    return max_len;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  node.resize(n);
  int x,y;
  dp.resize(n,-1);

  rep(i,m){
      cin>>x>>y;
      x--,y--;
      node[x].pb(y);
  }
  int res=-1;
  rep(i,n){
      res = max(res,dfs(i,0));
  }
  cout<<res<<endl;
  return 0;
}