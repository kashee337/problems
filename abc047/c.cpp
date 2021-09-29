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
bool done(string s){
    char c =s[0];
    int n = s.size();
    reps(i,n,1){
        if(c!=s[i]){
            return false;
        }
    }
    return true;
}
int main(){
cin.tie(0);
ios::sync_with_stdio(false);
string s;
cin>>s;
int n = s.size();
int res=0;
while(!done(s)){
    char c = s[0] =='W'?'B':'W';
    int w;
    reps(i,n,1){
        if(s[i]==c){
            w=i;
            break;
        }
    }
    s = s.substr(w,n-w); 
    res++;
}
cout<<res<<endl;
return 0;
}