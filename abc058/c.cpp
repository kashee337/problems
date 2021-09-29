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
vector<string> s(n);
rep(i,n){
    cin>>s[i];
    sort(s[i].begin(),s[i].end());
}
map<char,map<int,int>> dic;
rep(i,n){
    int m=s[i].size();
    int j=0;
    while(j<m){
        char c=s[i][j];
        int num=1;
        while(j<m&&c==s[i][j]){
            dic[c][num]++;
            num++;
            j++;
        }
    }
}
string ans="";
for(auto v:dic){
    string t="";
    int num=0;
    for(auto d:v.second){
        if(d.second==n){
            num=max(d.first,num);
        }
    }
    rep(i,num){
        t=t+v.first;
    }
    ans=ans+t;
}
sort(ans.begin(),ans.end());
cout<<ans<<endl;
return 0;
}