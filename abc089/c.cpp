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
map<char,ll> dic;
rep(i,n){
    string s;
    cin>>s;
    dic[s[0]]++;
}

string march="MARCH";
ll ans=0;
rep(i,5){
    reps(j,5,i+1){
        reps(k,5,j+1){
            char c1=march[i];
            char c2=march[j];
            char c3=march[k];
            ans+=dic[c1]*dic[c2]*dic[c3];
        }
    }
}
cout<<ans<<endl;
return 0;
}