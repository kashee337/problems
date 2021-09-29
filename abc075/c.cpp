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

vector<vector<int>> G;
vector<bool> visited;
map<pair<int, int>, bool> avoid;
void dfs(int at, int parent) {
    visited[at] = true;
    for (auto to : G[at]) {
        if (avoid[{at, to}] || avoid[{to, at}]) continue;
        if (to == parent) continue;
        if (!visited[to]) dfs(to, at);
    }
    return;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    G.resize(n);
    vector<pair<int, int>> ab(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a > b) swap(a, b);
        ab[i] = {a, b};
        G[a].pb(b);
        G[b].pb(a);
    }
    int res = 0;
    rep(i, m) {
        visited.assign(n, false);
        avoid[ab[i]] = true;
        dfs(0, -1);
        avoid.clear();
        rep(j, n) {
            if (!visited[j]) {
                res++;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}