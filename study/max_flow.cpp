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
struct edge {
    int to;
    ll cap;
    int rev;
};
constexpr long long MAX_V = 101;

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap) {
    G[from].pb((edge){to, cap, (int)G[to].size()});
    G[to].pb((edge){from, 0, (int)G[from].size() - 1});
}
int dfs(int v, int t, ll f) {
    if (v == t) return f;
    used[v] = true;
    rep(i, G[v].size()) {
        edge& e = G[v][i];
        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v, n;
    cin >> v >> n;
    rep(i, n) {
        int from, to, cap;
        cin >> from >> to >> cap;
        add_edge(from, to, cap);
    }
    ll res = 0;
    while (1) {
        memset(used, false, sizeof(used));
        int flow = dfs(0, v - 1, INF);
        if (flow == 0) break;
        res += flow;
    }
    cout << res << endl;
    return 0;
}