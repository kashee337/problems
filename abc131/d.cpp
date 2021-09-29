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
vector<pair<int,int>>ba(n);
rep(i,n){
    int a,b;
    cin>>a>>b;
    ba[i]={b,a};
}
sort(ba.begin(),ba.end());
int now_t=0;
string ans="Yes";
rep(i,n){
    int b=ba[i].first;
    int a=ba[i].second;
    if(b<a+now_t){
        ans="No";
        break;
    }
    now_t=a+now_t;
}
cout<<ans<<endl;
return 0;
}