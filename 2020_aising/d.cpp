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
int popcount(string x){
    int n=x.size();
    int cnt=0;
    rep(i,n){
        if(x[i]=='1')cnt++;
    }
    return cnt;
}
string bitmod(string x,uint mask){
    std::bitset<20> bs(mask);
    std::string s = bs.to_string();
    string res="";
    int nx=x.size();
    int n = min(20,nx);

    rep(i,n){
        if(x[nx-1-i]=='1'&&s[20-i-1]=='1'){
            res=res+'1';
        }
        else{
            res=res+'0';
        }
    }
    reverse(res.begin(),res.end());

    return res;
}
int main(){
cin.tie(0);
ios::sync_with_stdio(false);
ll n;
string x;
cin>>n>>x;
rep(i,n){
    int ans=0;
    string _x=x;
    _x[i]= x[i]=='1' ?'0':'1';
    int pcnt=popcount(_x);
    while(pcnt!=0){
        _x=bitmod(_x,pcnt-1);
        pcnt=popcount(_x);
        ans++;
    }
    cout<<ans<<endl;
}
return 0;
}