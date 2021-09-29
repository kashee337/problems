#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define P  pair<int,int>
using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;
string grid[(int)(1e6)+1];
int h,w,k;
int sx, sy, gx, gy;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
vector<vector<int>> dist;
void bfs(){
    queue<P> q;
    q.push({sx,sy});
    dist[sx][sy]=0;
    while(!q.empty()){
        auto from = q.front();q.pop();
        int fx=from.first,fy=from.second;
        rep(d,4){
            reps(m,k+1,1){
                int tx=fx+dx[d]*m;
                int ty=fy+dy[d]*m;
                if(tx<0||tx>=h||ty<0||ty>=w)continue;
                if(grid[tx][ty]=='@')break;
                if(dist[tx][ty] !=-1 && dist[tx][ty]<=dist[fx][fy])break;
                if(dist[tx][ty] !=-1) continue;
                dist[tx][ty] = dist[fx][fy]+1;
                q.push({tx,ty});
            }
        }
    }
}
int main(){
cin.tie(0);
ios::sync_with_stdio(false);

cin>>h>>w>>k;
dist=vector<vector<int>>(h,vector<int>(w,-1));
cin>>sx>>sy>>gx>>gy;
sx--,sy--,gx--,gy--;
rep(i,h){
    cin>>grid[i];
}

bfs();
cout<<dist[gx][gy]<<endl;

return 0;
}