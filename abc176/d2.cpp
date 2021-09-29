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
    int cw, ch, dw, dh;
    cin >> ch >> cw >> dh >> dw;
    ch--, cw--, dh--, dw--;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<int>> area(h, vector<int>(w, -1));
    int dx_paint[4] = {-1, 1, 0, 0};
    int dy_paint[4] = {0, 0, -1, 1};
    auto paint_bfs = [&](int x, int y, int cnt) {
        area[y][x] = cnt;
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            int crr_x = v.first;
            int crr_y = v.second;

            rep(i, 4) {
                int nx = crr_x + dx_paint[i];
                int ny = crr_y + dy_paint[i];
                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                if (area[ny][nx] >= 0) continue;
                if (s[ny][nx] == '#') continue;
                area[ny][nx] = cnt;
                q.push({nx, ny});
            }
        }
    };

    int cnt = 0;
    rep(i, h) {
        rep(j, w) {
            if (s[i][j] == '.') {
                if (area[i][j] >= 0) continue;
                paint_bfs(j, i, cnt++);
            }
        }
    }

    vector<set<int>> connect(cnt);
    int dx_warp[5] = {-2, -1, 0, 1, 2};
    int dy_warp[5] = {-2, -1, 0, 1, 2};
    auto warp_search = [&]() {
        rep(crr_y, h) {
            rep(crr_x, w) {
                if (s[crr_y][crr_x] == '#') continue;
                int par = area[crr_y][crr_x];
                rep(i, 5) {
                    rep(j, 5) {
                        int nx = crr_x + dx_warp[i];
                        int ny = crr_y + dy_warp[j];
                        if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                        if (s[ny][nx] == '#') continue;
                        int to = area[ny][nx];
                        if (to == -1) { cout << nx << " " << ny << endl; }
                        if (par != to) {
                            connect[par].insert(to);
                            connect[to].insert(par);
                        }
                    }
                }
            }
        }
    };

    warp_search();

    vector<int> dist(cnt, -1);
    auto last_bfs = [&](int start) {
        dist[start] = 0;
        queue<pair<int, int>> q;
        q.push({start, 0});
        while (!q.empty()) {
            auto v = q.front();
            int crr = v.first;
            int d = v.second;
            q.pop();
            for (auto next : connect[crr]) {
                if (dist[next] >= 0) continue;
                dist[next] = d + 1;
                q.push({next, d + 1});
            }
        }
    };
    last_bfs(area[ch][cw]);
    cout << dist[area[dh][dw]] << endl;
    return 0;
}