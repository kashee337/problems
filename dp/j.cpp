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
double dp[330][330][330];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    vector<int> cnt(4,0);
    rep(i,n){
        cin>>a;
        cnt[a]++;
    }

    rep(i,n+1){
        rep(j,n+1){
            rep(k,n+1){
                int m = i+j+k;
                if(m==0)continue;
                dp[i][j][k]=double(n)/m;//m個食べる期待値
                if(i>0)dp[i][j][k]+=dp[i-1][j+1][k]*double(i)/m;//iの山から個食べる期待値
                if(j>0)dp[i][j][k]+=dp[i][j-1][k+1]*double(j)/m;
                if(k>0)dp[i][j][k]+=dp[i][j][k-1]*double(k)/m;
            }
        }
    }
    cout<<fixed<<setprecision(10)<<dp[cnt[3]][cnt[2]][cnt[1]]<<endl;
    return 0;
}