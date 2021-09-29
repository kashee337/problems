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
vector<vector<ll>> dp(1000,vector<ll>(2001,-1));
ll dfs(int num,int v){
    if(v<0)return 0;
    if(num==0){
        if(v!=0)return 0;
        else return 1;
    } 
    if(dp[num][v]!=-1)return dp[num][v];
    ll res=0;
    reps(i,v-(num-1)*3+1,3){
        res = (res+dfs(num-1,v-i))%MOD;
    }
    return dp[num][v]=res;
}
int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int s;
cin>>s;
ll res = 0;
ll num = ceil(s/3.0);
reps(i,num+1,1){
    res= (res+dfs(i,s))%MOD;
}
cout<<res<<endl;
return 0;
}