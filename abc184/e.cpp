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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    map<char, vector<pair<int, int>>> warp;

    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
            if (a[i][j] != '#' && a[i][j] != '.') { warp[a[i][j]].pb({j, i}); }
        }
    }

    vector<vector<bool>> used(h, vector<bool>(w, false));
    vector<vector<ll>> dist(h, vector<ll>(w, -1));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

    auto goal = warp['G'][0];
    auto start = warp['S'][0];
    used[start.second][start.first] = true;
    dist[start.second][start.first] = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    q.push({0, {start.first, start.second}});
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int d = p.first;
        int x = p.second.first;
        int y = p.second.second;

        rep(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h || a[ny][nx] == '#') continue;
            if (used[ny][nx]) continue;
            dist[ny][nx] = d + 1;
            used[ny][nx] = true;
            q.push({d + 1, {nx, ny}});
        }

        for (auto w : warp[a[y][x]]) {
            if (w.first == x && w.second == y) continue;
            int nx = w.first;
            int ny = w.second;
            if (used[ny][nx]) continue;
            used[ny][nx] = true;
            dist[ny][nx] = d + 1;
            q.push({d + 1, {nx, ny}});
        }

        if (used[goal.second][goal.first]) break;
    }
    cout << dist[goal.second][goal.first] << endl;
    return 0;
}