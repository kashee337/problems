#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>
#include <sstream>

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

bool ok=false;

if(s.size()==1){
    if(s=="8")ok=true;
}
else if(s.size()==2){
    if(stoi(s)%8==0)ok=true;
    swap(s[0],s[1]);
    if(stoi(s)%8==0)ok=true;
}
else{
    vector<int> cnt(10,0);
    for(auto c:s)cnt[c-'0']++;    
    for(int i=0;i<1000;i+=8){
        ostringstream ss;
        ss << setw(3) << setfill('0') << i;
        string _s(ss.str());
        auto _cnt=cnt;
        for(auto c:_s)_cnt[c-'0']--;
        
        if(all_of(_cnt.begin(),_cnt.end(),[](int x){return x>=0;})){
            ok=true;
            break;
        }
    }
}

if(ok)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
return 0;
}