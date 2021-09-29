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
int h, w;
vector<string> c;
vector<vector<bool>> used;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
ll dfs(int cx, int cy, ll k, int sx, int sy) {
    if (cx == sx && cy == sy && used[sy][sx]) { return k; }
    if (used[cy][cx]) return -1;
    used[cy][cx] = true;
    ll _k = k;
    k = -1;
    rep(i, 4) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
        if (c[ny][nx] == '#') continue;
        k = max(k, dfs(nx, ny, _k + 1, sx, sy));
    }
    used[cy][cx] = false;
    return k;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    c.resize(h);
    used.assign(h, vector<bool>(w, false));
    rep(i, h) cin >> c[i];
    ll res = -1;
    rep(y, h) {
        rep(x, w) { res = max(res, dfs(x, y, 0, x, y)); }
    }
    if (res < 3) res = -1;
    cout << res << endl;
    return 0;
}