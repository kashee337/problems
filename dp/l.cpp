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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    vector<vector<ll>>dp(n,vector<ll>(n,0));
    int turn=(n%2==0)?-1:1;
    rep(l,n)dp[l][l]=turn*a[l];
    turn*=-1;
    reps(w,n,1){
        rep(l,n-w){
            int r = l + w;
            ll lv = dp[l+1][r]+turn*a[l];
            ll rv = dp[l][r-1]+turn*a[r];
            if(turn>0)dp[l][r]= max(lv,rv);
            else dp[l][r]= min(lv,rv);
        }
        turn*=-1;
    } 
    cout<<dp[0][n-1]<<endl;
    return 0;
}