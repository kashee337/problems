#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>

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

int n;
ll solve(string s,int d,int sum){
    if(d==n)return sum+stol(s);
    int idx = d-(n-s.size());
    string ls=s.substr(0,idx);
    string rs=s.substr(idx,s.size()-idx);
    ll res0 = solve(rs,d+1,sum+stol(ls));
    ll res1 = solve(s,d+1,sum);
    return res0+res1;
}

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
string s;
cin>>s;
n = s.size();

cout<<solve(s,1,0)<<endl;
return 0;
}