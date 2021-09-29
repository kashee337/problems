#include <bits/stdc++.h>

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
ll n;
cin>>n;
vector<ll>A(n);
rep(i,n)cin>>A[i];
sort(A.begin(),A.end(),greater<ll>());
ll ans=A[0];
int idx=1;
int cnt=0;
reps(i,n,2){
    ans+=A[idx];
    cnt++;
    if(cnt==2){
        idx++;
        cnt=0;
    }
}
cout<<ans<<endl;
return 0;
}