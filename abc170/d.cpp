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
ll n;
cin>>n;
vector<ll>a(n);
rep(i,n)cin>>a[i];
sort(a.begin(),a.end());

int res=0;
vector<int> used(3*(int)1e6,false);
map<int,int> same;
vector<int> valid;
rep(i,n){
    same[a[i]]++;
    if(used[a[i]])continue;
    valid.pb(a[i]);
    int num=a[n-1]/a[i];
    reps(j,num+2,1){
        used[a[i]*j]=true;
    }
    res++;
}
for(auto v:valid){
    if(same[v]>=2)res--;
}
cout<<res<<endl;
return 0;
}