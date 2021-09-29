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

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int n;
cin>>n;
string s;
cin>>s;

vector<int> cnt(n);
int r_cnt=0;

rrep(i,n){
    if(s[i]=='R')r_cnt++;
    else cnt[i]=r_cnt;
}

int res=0;
if(r_cnt>0 && cnt.size()>0){
    int w=0;
    rep(i,n){
        if(s[i]=='W'){
            if(cnt[i]-w>0){
                w++;
                res++;
            }
        }
    }
}

cout<<res<<endl;

return 0;
}