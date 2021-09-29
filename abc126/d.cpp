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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<vector<pair<int, int>>> G(n);
    int u, v, w;
    rep(i, n - 1) {
        cin >> u >> v >> w;
        u--, v--;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }
    vector<int> res(n, 0);
    function<void(int, int, int)> dfs = [&](int crr, int par, int c) {
        res[crr] = c;
        for (auto v : G[crr]) {
            if (v.first == par) continue;
            if (v.second & 1)
                dfs(v.first, crr, 1 - c);
            else
                dfs(v.first, crr, c);
        }
    };
    dfs(0, -1, 1);
    for (auto c : res) cout << c << endl;
    return 0;
}