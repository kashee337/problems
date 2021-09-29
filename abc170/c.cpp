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
int x,n;
cin>>x>>n;
map<int,int>p;

rep(i,n){
    int a;
    cin>>a;
    p[a]++;
}
int u,d;
rep(i,100){
    if(!p.count(x+i)){
        u=x+i;
        break;
    }
}
rep(i,100){
    if(!p.count(x-i)){
        d=x-i;
        break;
    }
}
if(abs(x-u)>abs(x-d)){
    cout<<d<<endl;
}
else if(abs(x-u)==abs(x-d)){
    cout<<min(u,d)<<endl;
}
else{
    cout<<u<<endl;
}
return 0;
}