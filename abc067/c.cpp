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
int n;
cin>>n;
vector<ll>a(n);
rep(i,n)cin>>a[i];
vector<ll>s(n,0);
s[0]=a[0];
rep(i,n-1){
    s[i+1]=s[i]+a[i+1];
}
ll res=INF;
rep(i,n-1){
    ll x=s[i];
    ll y=s[n-1]-s[i];
    res=min(res,abs(x-y));
}
cout<<res<<endl;
return 0;
}