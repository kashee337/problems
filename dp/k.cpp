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
vector<int>a;
vector<vector<int>>dp;
int min_val;
int n,k;
bool dfs(int i,int turn){
    if(i>k)return false;
    if(k-i<min_val)return true;
    if(dp[i][turn]!=-1)return !dp[i][turn];
    bool res = false;

    for(auto d:a){
        bool res_tmp = dfs(i+d,(turn+1)%2);
        if(res_tmp){
            res = res_tmp;
            break;
        }
    }
    dp[i][turn] = res;
    return !res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    a.resize(n);
    rep(i,n)cin>>a[i];
    min_val=*min_element(a.begin(),a.end());
    dp.resize(k+1,vector<int>(2,-1));
    dfs(0,0);
    if(dp[0][0])cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}