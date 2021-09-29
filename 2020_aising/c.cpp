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
ll N;
cin>>N;
reps(n,N+1,1){
    ll r=sqrt(2*n);
    int cnt=0;
    reps(x,r+1,1){
        reps(y,r+1-x,1){
            ll b=x+y;
            ll c= x*x+ y*y + x*y-n;
            ll d=b*b-4*c;
            
            if(d>0&&ceil(sqrt(d)) == floor(sqrt(d))&&(-b+sqrt(d))>=1){
                cnt++;
            }
        }   
    }
    cout<<cnt<<endl;
}
return 0;
}