#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  string s,t;
  cin>>s>>t;
  int n=s.size();
  int m=t.size();
  vector<vector<int>>dp(n+1,vector<int>(m+1,0));

  //各状態でのLCS長さをメモ
  rep(i,n){
      rep(j,m){
        if(s[i]==t[j]){//同じ文字なら
            dp[i+1][j+1]=dp[i][j]+1;
        }
        else{
            dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
      }
  }
  //後ろから辿っていきLCSを復元
  int i=n,j=m;
  string ans="";
  while(i>0&&j>0){
      if(s[i-1]==t[j-1]){
          ans+=s[i-1];
          i--;j--;
      }
      else{
          if(dp[i][j]==dp[i-1][j]){
              i--;
          }
          else{
              j--;
          }
      }
  }
  //後ろ向きにメモしたので逆順に直す
  reverse(ans.begin(),ans.end());

  cout<<ans<<endl;
  return 0;
}