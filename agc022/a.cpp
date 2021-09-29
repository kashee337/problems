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
string s;
cin>>s;
int n=s.size();
string ans;
if(n<26){
    map<char,int> dic;
    rep(i,n){
        dic[s[i]]++;
    }
    rep(i,26){
        char c = 'a' + i;
        if(!dic[c]){
            ans=s+c;
            break;
        }
    }
}
else{
    if(s=="zyxwvutsrqponmlkjihgfedcba"){
        ans="-1";
    }
    else{
        string _s=s;
        next_permutation(_s.begin(),_s.end());
        rep(i,26){
            if(s[i]!=_s[i]){
                ans=_s.substr(0,i+1);
                break;
            }
        }
    }
}
cout<<ans<<endl;
return 0;
}