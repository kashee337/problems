#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
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
int n;
vector<int>p;
set<int>score;
vector<vector<bool>>visited(101,vector<bool>(10000,false));
void solve(int i,int w){
    if(visited[i][w])return;
    visited[i][w]=true;
    
    if(i==n){
        score.insert(w);
        return;
    }
    
    solve(i+1,w+p[i]);
    solve(i+1,w);
    return;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n;
  p.resize(n);
  rep(i,n)cin>>p[i];
  solve(0,0);
  cout<<score.size()<<endl;
  return 0;
}