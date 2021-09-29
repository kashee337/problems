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
vector<ll>h(n),s(n);
rep(i,n)cin>>h[i]>>s[i];
ll left=0,right=INF;
while(right-left>1){
    ll mid =(left+right)/2;
    vector<ll> limit(n,0);
    bool ok=true;
    rep(i,n){
        if(mid<h[i]){
            ok=false;
            break;
        }
        else{
            limit[i]=(mid-h[i])/s[i];
        }
    }
    if(!ok){
        left=mid;
        continue;
    }
    sort(limit.begin(),limit.end());
    rep(i,n){
        if(limit[i]<i){
            ok=false;
            break;
        }
    }
    if(ok)right=mid;
    else left=mid;
}
    cout<<right<<endl;
return 0;
}