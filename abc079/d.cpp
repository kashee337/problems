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
ll c[10][10];
ll dfs(int from, ll cost, vector<bool> used) {
    if (from == 1) { return cost; }
    ll min_val = INF;
    rep(to, 10) {
        if (used[to]) continue;
        used[to] = true;
        min_val = min(min_val, dfs(to, cost + c[from][to], used));
        used[to] = false;
    }
    return min_val;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    rep(i, 10) { rep(j, 10) cin >> c[i][j]; }
    map<int, int> d;
    vector<bool> used(10, false);
    rep(i, 10) {
        used[i] = true;
        d[i] = dfs(i, 0, used);
        used[i] = false;
    }
    ll res = 0;
    rep(i, h) {
        rep(j, w) {
            int a;
            cin >> a;
            if (a == -1) continue;
            res += d[a];
        }
    }
    cout << res << endl;
    return 0;
}