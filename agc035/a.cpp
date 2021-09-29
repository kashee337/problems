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
vector<int>a(n);
map<int,int>dic;
rep(i,n){
    cin>>a[i];
    dic[a[i]]++;
}
int cnt=dic.size();
string judge="Yes";
if(cnt==3){
    int res=0;
    for(auto v:dic){
        res=res^v.first;
        if(v.second*3!=n){
            judge="No";
            break;
        }
    }
    if(res!=0){
        judge="No";
    }
}
else if(cnt==2){
    for(auto v:dic){
        if(v.first==0){
            if(v.second*3!=n){
                judge="No";
                break;
            }
        }
        else{
            if(v.second*3!=2*n){
                judge="No";
                break;
            }
        }
    }
}
else if(cnt==1){
    for(auto v:dic){
        if(v.first!=0){
            judge="No";
            break;
        }
    }
}
else{
    judge="No";
}
cout<<judge<<endl;
return 0;
}