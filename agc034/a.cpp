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
int n,a,b,c,d;
cin>>n>>a>>b>>c>>d;
a--,b--,c--,d--;
string s;
cin>>s;

vector<bool>dp_snuke(n,false);
vector<bool>dp_hnuke(n,false);
dp_snuke[a]=true;
dp_hnuke[b]=true;
rep(i,n-1){
    if(dp_snuke[i]){
        if(s[i+1]!='#')dp_snuke[i+1]=true;
        if(i+2<n&&s[i+2]!='#')dp_snuke[i+2]=true;
    } 
    if(dp_hnuke[i]){
        if(s[i+1]!='#')dp_hnuke[i+1]=true;
        if(i+2<n&&s[i+2]!='#')dp_hnuke[i+2]=true;
    } 
}    
if(dp_snuke[c]&&dp_hnuke[d]){
    if(c<d){
        cout<<"Yes"<<endl;
    }
    else{
        reps(i,d+1,b){
            if(s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.'){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        cout<<"No"<<endl;
    }
}
else{
    cout<<"No"<<endl;
}

return 0;
}