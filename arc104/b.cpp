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

bool check(map<char,int> memo){
    return (memo['A']==memo['T']) && (memo['C']==memo['G']);
}

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
ll n;
string s;
cin>>n>>s;
ll cnt=0;
map<char,int> memo;
rep(i,n){
    map<char,int> memo;
    reps(j,n,i){
        memo[s[j]]++;
        if(check(memo))cnt++;
    }
}
cout<<cnt<<endl;
return 0;
}