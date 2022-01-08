#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n, s) for (int i = (s); i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define rreps(i, n, s) for (int i = s; i >= n; i--)

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;
constexpr long long MAX_V = 101;

int V;
struct edge {
    int to;
    ll cap, cost;
    int rev;
};
vector<edge> G[MAX_V];
bool used[MAX_V];
ll dist[MAX_V];
ll prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost) {
    G[from].pb((edge){to, cap, cost, (int)G[to].size()});
    G[to].pb((edge){from, 0, -cost, (int)G[from].size() - 1});
}
int min_cost_flow(int s, int t, int f) {
    int res = 0;
    while (f > 0) {
        //頂点毎の最小距離を初期化
        fill(dist, dist + V, INF);
        dist[s] = 0;
        bool update = true;
        // Bellman-Fordで更新していく
        while (update) {
            update = false;
            rep(v, V) {
                if (dist[v] == INF) continue;
                rep(i, G[v].size()) {
                    edge& e = G[v][i];
                    //負のコストを持つ辺のときは更新しない
                    if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                        dist[e.to] = dist[v] + e.cost;
                        //最短距離が更新されたときは、やってきた頂点と辺を記録しておく
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update = true;
                    }
                }
            }
        }
        //到達不可能だった場合は終了
        if (dist[t] == INF) return -1;

        // tから逆向きに最短距離上の最小キャパシティとなるボトルネックの値を求める
        ll d = f;
        for (int v = t; v != s; v = prevv[v]) {
            ll cap = G[prevv[v]][preve[v]].cap;
            d = min(d, cap);
        }
        // 流せる量を更新し、流した量で各辺のcapを更新する
        f -= d;
        res += d * dist[t];
        for (int v = t; v != s; v = prevv[v]) {
            edge& e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int e;
    ll f;
    cin >> V >> e >> f;
    rep(i, e) {
        int from, to, cap, cost;
        cin >> from >> to >> cap >> cost;
        add_edge(from, to, cap, cost);
    }
    cout << min_cost_flow(0, V - 1, f) << endl;
    return 0;
}