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
string dic = "abcdefghijklmnopqrstuvwxyz";
vector<char> encode;
string ans="";

int digit=1;
ll tmp=26;
while(tmp < n) {
    digit++;
    tmp+=powl(26,digit);
}
ll _n=n-(tmp/26);
rep(i,digit){
    int j=_n%26;
    _n/=26;
    encode.pb(dic[j]);
}
reverse(encode.begin(),encode.end());
for(auto c:encode){
    ans=ans+c;
}
cout<<ans<<endl;
return 0;
}