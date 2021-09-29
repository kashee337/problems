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
vector<int>b(n);
rep(i,n){
    cin>>b[i];
}

// 逆から考える.最後の操作が終わったときに置いたものであり得るのはb_k=kのモノだけ。
// なのでb_k=kとなるb_kを順に消し、aに格納していき、最後にそれを逆順に展開すれば操作順になる。

vector<int>a(n);
rep(i,n){
    int idx=-1;
    rep(j,n-i){
        if(b[j]==j+1){
            idx=j;
        }
    }
    if(idx<0)continue;
    a[i]=b[idx];
    b.erase(b.begin()+idx);
}
if(b.empty()){
    rrep(i,n){
        cout<<a[i]<<endl;
    }
}
else{
    cout<<-1<<endl;
}

return 0;
}