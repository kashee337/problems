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
int n;
cin>>n;
vector<ll> x(n);
ll m_dist =0;
double e_dist =0;
ll c_dist =0;
rep(i,n){
    cin>>x[i];
    m_dist+=abs(x[i]);
    e_dist+=x[i]*x[i];
    c_dist = max(c_dist,abs(x[i]));
}
cout<<m_dist<<endl;
cout<<fixed<<setprecision(10)<<sqrt(e_dist)<<endl;
cout<<c_dist<<endl;

return 0;
}