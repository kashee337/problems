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
int n;
cin>>n;
vector<ll>a(n),b(n),diff(n);
rep(i,n)cin>>a[i];
rep(i,n){
    cin>>b[i];
    diff[i]=a[i]-b[i];
}
int ans;
if(accumulate(diff.begin(),diff.end(),0LL)<0){
    ans=-1;
}
else{
    sort(diff.begin(),diff.end());
    int i=0,j=0;
    int v=0;
    while(diff[i]<0){
        if(v>=abs(diff[i])){
            v+=diff[i];
            i++;
        }
        else{
            v+=diff[(n-1)-j];
            j++;
        }
    }
    ans=i+j;
}
cout<<ans<<endl;
return 0;
}