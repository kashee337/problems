#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define eb emplace_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n, s) for (int i = (s); i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define rreps(i, n, s) for (int i = s; i >= n; i--)

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> G(n);
    vector<pair<int, int>> vp;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].eb(b);
        G[b].eb(a);
        vp.eb(a, b);
    }
    int k = 0;
    map<pair<int, int>, int> I;
    vector<int> c(n, 0);

    queue<int> q;
    vector<bool> used(n, false);
    used[0] = 1;
    q.emplace(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        k = max(k, (int)G[v].size());
        int cur = 1;
        for (int u : G[v]) {
            if (used[u]) continue;
            if (cur == c[v]) cur++;
            c[u] = I[{u, v}] = I[{v, u}] = cur++;
            used[u] = true;
            q.emplace(u);
        }
    }
    cout << k << endl;
    for (auto p : vp) cout << I[p] << endl;
    return 0;
}