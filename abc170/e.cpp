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
ll n,q;
cin>>n>>q;
vector<multiset<int>> kgarden(2*(int)(1e5)+1);
map<int,int> belongs;
map<int,int> rates;

rep(i,n){
    int a,b;
    cin>>a>>b;
    b--;
    kgarden[b].insert(a);
    belongs[i]=b;
    rates[i]=a;
}
multiset<int> best_rates;
for(auto v:kgarden){
    if(v.empty())continue;
    best_rates.insert(*v.rbegin());
}
vector<int> equality;
rep(i,q){
    int c,d;
    cin>>c>>d;
    c--,d--;
    
    //移動前の幼稚園
    int _d=belongs[c];

    //最強集団から元の最強を削除
    best_rates.erase(best_rates.find(*kgarden[_d].rbegin()));
    //元の幼稚園から移動対象園児を削除
    kgarden[_d].erase(kgarden[_d].find(rates[c]));
    //空でなければ新たな最強園児を最強集団に追加
    if(!kgarden[_d].empty()){
        best_rates.insert(*kgarden[_d].rbegin());
    }
    //移動先の元の最強園児を最強集団から削除
    if(!kgarden[d].empty()){
        best_rates.erase(best_rates.find(*kgarden[d].rbegin()));
    }
    //園児を移動
    kgarden[d].insert(rates[c]);
    //移動先での新たな最強園児を最強集団に追加
    best_rates.insert(*kgarden[d].rbegin());

    //所属を変更
    belongs[c]=d;
    //結果を保存
    equality.pb(*best_rates.begin());
}

for(auto v:equality){
    cout<<v<<endl;
}
return 0;
}