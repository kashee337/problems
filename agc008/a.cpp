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
ll x,y;
cin>>x>>y;
ll res;
if(x>y){
    if(abs(x)<abs(y)){
        if(x<0&&y<0){
            res=abs(y)-abs(x)+2;
        }
        else if(y<0){
            res=abs(y)-abs(x)+1;
        }
        else{
            res = -y+x;
        }
    }
    else{
        if(x>0&&y>0){
            res=y+x+1;
        }
        else{
            res=y+x+1;
        }
    }
}
else{
    if(abs(x)<abs(y)){
        if(x<0){
            res=abs(y)-abs(x)+1;
        }
        else{
            res=abs(y)-abs(x);
        }
    }
    else{
        if(x<0&&y>0){
            res=abs(x)-abs(y)+1;
        }
        else{
            res=abs(x)-abs(y);
        }
    }
}
cout<<res<<endl;

return 0;
}