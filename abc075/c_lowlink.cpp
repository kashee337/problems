#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
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

vector<int> ord, lowlink;
vector<bool> used;
vector<vector<int>> G;
vector<pair<int, int>> bridge;

void dfs(int at, int par, int k) {
    used[at] = true;
    ord[at] = lowlink[at] = k++;
    for (int to : G[at]) {
        if (to == par) continue;
        if (!used[to]) {
            dfs(to, at, k);
            lowlink[at] = min(lowlink[at], lowlink[to]);
        } else {
            lowlink[at] = min(lowlink[at], ord[to]);
        }
        if (ord[at] < lowlink[to]) bridge.pb({at, to});
    }

    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    // init
    G.resize(n);
    ord.resize(n);
    lowlink.resize(n);
    used.assign(n, false);

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(0, -1, 0);
    cout << bridge.size() << endl;
    return 0;
}