#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
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

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
ll n,m;
cin>>n>>m;
vector<ll>h(n),w(m);
rep(i,n)cin>>h[i];
rep(i,m)cin>>w[i];
sort(h.begin(),h.end());
sort(w.begin(),w.end());

ll ans=INF;
vector<ll>sl((n-1)/2+1,0);
vector<ll>sr((n-1)/2+1,0);
rep(i,(n-1)/2){
    sl[i+1]=abs(h[2*i+1]-h[2*i]+sl[i]);
    sr[i+1]=abs(h[(n-1)-(2*i+1)]-h[(n-1)-(2*i)])+sr[i];
}


rep(i,n){
    int h1=h[i];
    int h2;
    auto it = lower_bound(w.begin(),w.end(),h1);
    int index = distance(w.begin(),it);

    if(index>0 && index<m){
        h2 = abs(w[index]- h1)<abs(w[index-1]- h1)? w[index]:w[index-1];
    }
    else if(index==0){
        h2=w[index];
    }
    else{
        h2=w[m-1];
    }
    ll tmp_sub=abs(h1-h2);
    if(i==0){
        tmp_sub+=sr[(n-1)/2];
    }
    else if(i==n-1){
        tmp_sub+=sl[(n-1)/2];
    }
    else{
        if(i%2==0){
            int _sl =sl[i/2];
            int _sr= sr[(n-(i+1))/2];
            tmp_sub+=_sl+_sr;
        }
        else{
            tmp_sub+=abs(h[i-1]-h[i+1]);
            int _sl =sl[((i-2)+1)/2];
            int _sr= sr[(n-(i+2))/2];
            tmp_sub+=_sl+_sr;
        }
    }
    ans =min(ans,tmp_sub);

}
cout<<ans<<endl;
return 0;
}