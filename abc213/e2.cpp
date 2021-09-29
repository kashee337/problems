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

struct Point {
    Point(int _x, int _y) : x(_x), y(_y) {}
    int x;
    int y;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    deque<pair<Point, int>> q;
    Point p0(0, 0);
    q.push_back({p0, 0});
    vector<vector<bool>> used(h, vector<bool>(w, false));
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    int dw[4][6] = {{-2, -2, -2, -1, -1, -1}, {-1, 0, 1, -1, 0, 1}, {2, 2, 2, 1, 1, 1}, {-1, 0, 1, -1, 0, 1}};
    int dh[4][6] = {{1, 0, -1, 1, 0, -1}, {-2, -2, -2, -1, -1, -1}, {1, 0, -1, 1, 0, -1}, {2, 2, 2, 1, 1, 1}};
    ll res;
    while (!q.empty()) {
        Point crr_p = q.front().first;
        int crr_cost = q.front().second;
        q.pop_front();
        if (used[crr_p.y][crr_p.x]) continue;
        if (crr_p.x == w - 1 && crr_p.y == h - 1) {
            res = crr_cost;
            break;
        }
        used[crr_p.y][crr_p.x] = true;
        rep(i, 4) {
            Point next_p(crr_p.x + dx[i], crr_p.y + dy[i]);
            if (next_p.x < 0 || next_p.x >= w || next_p.y < 0 || next_p.y >= h) continue;
            if (s[next_p.y][next_p.x] == '#') continue;
            q.push_front({next_p, crr_cost});
        }

        rep(i, 4) {
            rep(j, 6) {
                Point next_p(crr_p.x + dw[i][j], crr_p.y + dh[i][j]);
                if (next_p.x < 0 || next_p.x >= w || next_p.y < 0 || next_p.y >= h) continue;
                q.push_back({next_p, crr_cost + 1});
            }
        }
    }
    cout << res << endl;
    return 0;
}