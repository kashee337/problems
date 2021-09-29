#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
int main() {

  int n,m;
  cin>>n>>m;
  vector<vector<int>> node(n);
  rep(i,m){
    int x,y;
    cin>>x>>y;
    x--,y--;
    node[x].push_back(y);  
  }
  //入次数を数え、0のnodeから順に消していけばok
  vector<int>indeg(n,0);
  rep(i,n){
      for(auto v:node[i])indeg[v]++;
  }
  queue<int> q;
  rep(i,n){
      if(indeg[i]==0)q.push(i);
  }
  vector<int>res;
  while(!q.empty()){
      auto now = q.front();
      q.pop();
      for(auto next:node[now]){
          indeg[next]--;
          if(indeg[next]==0)q.push(next);
      }
      res.push_back(now);
  }
  
  cout<<"### result ###"<<endl;
  rep(i,n)cout<<res[i]+1<<endl;

  return 0;
}