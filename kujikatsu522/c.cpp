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
vector<priority_queue<ll>> g;
vector<bool> used;
vector<ll> res;
ll n;
void dfs(int from, int crr) {
    res.pb(crr);
    if (used[crr] && crr == 1) { return; }
    used[crr] = true;
    while (!g[crr].empty()) {
        int to = -g[crr].top();
        g[crr].pop();
        if (used[to]) continue;
        dfs(crr, to);
        res.pb(crr);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    g.resize(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push(-b);
        g[b].push(-a);
    }
    used.assign(n, false);
    dfs(-1, 0);
    for (auto crr : res) cout << crr + 1 << endl;
    return 0;
}