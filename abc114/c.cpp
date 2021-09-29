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
int n,d;
bool check(string s){
    bool three = (int)s.find("3")<0?0:1;
    bool five = (int)s.find("5")<0?0:1;
    bool seven = (int)s.find("7")<0?0:1;
    return three&&five&&seven;
}
int dfs(string s,bool ischecked){
    if(s.size()==d){
        if(n>=stoi(s)&&(ischecked||check(s)))
            return 1;
        else 
            return 0;
    }
    int res=0;
    if(ischecked||check(s))res++;
    return res+dfs(s+"3",res)+dfs(s+"5",res)+dfs(s+"7",res);
}
int main(){
cin.tie(0);
ios::sync_with_stdio(false);
cin>>n;
d=to_string(n).size();
cout<<dfs("",false)<<endl;
return 0;
}