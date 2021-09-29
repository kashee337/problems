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
int H,W,K;
cin>>H>>W>>K;
vector<string>c(H);
rep(i,H)cin>>c[i];
int nh=1<<H;
int nw=1<<W;
ll ans =0;
rep(i,nh){
    rep(j,nw){
        vector<string> tmp(c);
        rep(n,H){
            if(i&(1<<n)){
                tmp[n]="";
                rep(l,W){
                    tmp[n]=tmp[n]+'r';
                }
            }
        }
        rep(m,W){
            if(j&(1<<m)){
                rep(l,H){
                    tmp[l][m]='r';
                }
            }   
        }
        int cnt=0;
        rep(n,H){
            rep(m,W){
                if(tmp[n][m]=='#')cnt++;
            }
        }
        if(cnt==K)ans++;
    }
}
cout<<ans<<endl;
return 0;
}