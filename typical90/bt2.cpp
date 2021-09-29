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
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using vvb = vector<vector<bool>>;
ll dfs(int x, int y, int sx, int sy, int k, vvb visit) {
    if (sx == x && sy == y && visit[sy][sx]) return k > 2 ? k : -1;

    visit[y][x] = true;
    ll res = -1;
    rep(i, 4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
        if (c[ny][nx] == '#') continue;
        if (visit[ny][nx] && (sx != nx || sy != ny)) continue;
        res = max(res, dfs(nx, ny, sx, sy, k + 1, visit));
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    c.resize(h);
    rep(i, h) cin >> c[i];
    vvb visit(h, vector<bool>(w, false));
    ll res = -1;
    rep(y, h) rep(x, w) {
        if (c[y][x] == '#') continue;
        res = max(res, dfs(x, y, x, y, 0, visit));
    }
    cout << res << endl;
    return 0;
}