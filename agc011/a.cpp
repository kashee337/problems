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
int n,c,k;
cin>>n>>c>>k;
vector<int>t(n);
rep(i,n)cin>>t[i];
sort(t.begin(),t.end());
ll cnt=0;
int i=0;
while(i<n){
    int limit_t=t[i]+k;
    int tmp_cnt=0;
    reps(j,c+1,1){
        tmp_cnt++;
        if(i+j<n && t[i+j]>limit_t){
            break;
        }
    }
    if(tmp_cnt>1)i+=tmp_cnt;
    else i++;
    cnt++;
}
cout<<cnt<<endl;
return 0;
}