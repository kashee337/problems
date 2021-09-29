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
ll n;
cin>>n;
vector<pair<ll,ll>>pt;
rep(i,n){
    ll x,y;
    cin>>x>>y;
    pt.pb({x,y});
}
bool ok=false;
rep(i,n){
    reps(j,n,i+1){
        ll cnt=2;
        ll x1=pt[i].first;
        ll y1=pt[i].second;
        ll x2=pt[j].first;
        ll y2=pt[j].second;

        if(x1==x2){
            reps(k,n,j+1){
                ll x3=pt[k].first;
                if(x3==x1){
                    cnt++;
                }
            }
        }
        else{
            reps(k,n,j+1){
                ll x3=pt[k].first;
                ll y3=pt[k].second;
                ll left = (y3-y1)*(x2-x1);
                ll right = (x3-x1)*(y2-y1);
                if(left==right){
                    cnt++;
                }
            }
        }
        if(cnt>=3){
            ok=true;
        }

    }
}
if(ok)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
return 0;
}