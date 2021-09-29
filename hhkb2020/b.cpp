#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
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

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int H,W;
cin>>H>>W;
vector<string>s(H);
rep(i,H)cin>>s[i];
int ans=0;
rep(i,H){
    rep(j,W){
        if(s[i][j]=='.'){
            if(i+1<H&&s[i+1][j]=='.')
                ans++;
            if(j+1<W&&s[i][j+1]=='.')
                ans++;
        }
    }
}
cout<<ans<<endl;
return 0;
}