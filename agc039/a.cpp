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
ll calc_cnt(string s){
    int n=s.size();
    string t=s;
    ll cnt=0;
    rep(i,n){
        if(t[i+1]==t[i]){
            t[i+1]='A';
            cnt++;
        }
    }
    return cnt;
}
int main(){
cin.tie(0);
ios::sync_with_stdio(false);
string s;
cin>>s;
ll k;
cin>>k;
vector<ll> diff(3);
rep(i,3){
    string _s=s;
    rep(j,i){
        _s+=s;
    }
    diff[i]=calc_cnt(_s);
}
rreps(i,1,3){
diff[i]-=diff[i-1];
}

ll ans=diff[0];
rep(i,k-1){
    ans+=diff[i%2+1];
}
cout<<ans<<endl;
return 0;
}