#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
vector<vector<int>>memo;
bool func(int i,int w){
  if(memo[i][w]!=-1)return memo[i][w];

  if(i==0){
    if(w==0)return true;
    else return false;
  }
  
  int res=0;
  if(func(i-1,w))res=1;
  if(res||(w-a[i-1]>=0&&func(i-1,w-a[i-1])))res=1;

  return memo[i][w]=res;
}
int main(){
  int N,W;
  cin>>N>>W;
  a.resize(N);
  memo.resize(N+1,vector<int>(W+1,-1));
  for(int i=0;i<N;i++)cin>>a[i];
  if(func(N,W))cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
