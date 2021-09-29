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
int dx[2] = {1, 0};
int dy[2] = {0, 1};
vector<string> s;
vector<vector<ll>> area;
ll h, w;
ll bfs(int x, int y, int cnt) {
    if (area[y][x] >= 0) return cnt;
    queue<pair<ll, ll>> q;
    q.push({x, y});
    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        area[v.second][v.first] = cnt;
        rep(i, 2) {
            int nx = v.first + dx[i];
            int ny = v.second + dy[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (s[ny][nx] == '#') continue;
            if (area[ny][nx] >= 0) continue;
            q.push({nx, ny});
        }
    }
    return cnt + 1;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> h >> w;
    s = vector<string>(h);
    rep(i, h) cin >> s[i];
    queue<int> q;
    ll res = 0;
    if (s[0][0] == '#') {
        res++;
        s[0][0] = '.';
    }
    if (s[h - 1][w - 1] == '#') {
        res++;
        s[h - 1][w - 1] = '.';
    }
    area = vector<vector<ll>>(h, vector<ll>(w, -1));
    ll cnt = 0;
    rep(y, h) {
        rep(x, w) {
            if (s[y][x] == '.') { cnt = bfs(x, y, cnt); }
        }
    }
    return 0;
}