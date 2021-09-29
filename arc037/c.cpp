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

vector<ll>a,b;
bool c(ll x,ll k){
    ll left=-1;
    ll right=b.size();
    while(left+1<right){
        ll mid = (left+right)/2;
        if(b[mid]<x){
            left=mid;
        }
        else{
            right=mid;
        }
    }
    return right<k;
}
int main(){
cin.tie(0);
ios::sync_with_stdio(false);
ll n,k;
cin>>n>>k;
a.resize(n),b.resize(n);
rep(i,n)cin>>a[i];
rep(i,n)cin>>b[i];
sort(a.begin(),a.end());
sort(b.begin(),b.end());
vector<ll> num;
rep(i,n){
    ll left=0;
    ll right=1e9;
    while(left+1<right){
        ll mid=(left+right)/2;
        if(c(mid/a[i],k)){
            right=mid;
        }
        else{
            left=mid;
        }
    }
    num.push_back(right);
}
sort(num.begin(),num.end());
cout<<num[k-1]<<endl;
return 0;
}