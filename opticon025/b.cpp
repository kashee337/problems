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
ll h, w;
vector<string> c;
ll res = 0;
int dx[2] = {0, 1}, dy[2] = {1, 0};
vector<vector<ll>> used;
void dfs(int x, int y, ll depth) {
    res = max(res, depth);
    used[y][x] = depth;
    rep(i, 2) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
        if (c[ny][nx] == '#') continue;
        if (used[ny][nx] >= depth + 1) continue;
        dfs(nx, ny, depth + 1);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    c.resize(h);
    used.assign(h, vector<ll>(w, 0));
    rep(i, h) cin >> c[i];
    dfs(0, 0, 1);
    cout << res << endl;
    return 0;
}