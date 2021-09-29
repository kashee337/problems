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
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    priority_queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    vector<vector<bool>> used(h, vector<bool>(w, false));
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    int dw[4][6] = {{-2, -2, -2, -1, -1, -1}, {-1, 0, 1, -1, 0, 1}, {2, 2, 2, 1, 1, 1}, {-1, 0, 1, -1, 0, 1}};
    int dh[4][6] = {{1, 0, -1, 1, 0, -1}, {-2, -2, -2, -1, -1, -1}, {1, 0, -1, 1, 0, -1}, {2, 2, 2, 1, 1, 1}};
    ll res = 0;
    while (!q.empty()) {
        int crr_cost = -q.top().first;
        int crr_x = q.top().second.first;
        int crr_y = q.top().second.second;
        q.pop();
        if (used[crr_y][crr_x]) continue;
        if (crr_x == w - 1 && crr_y == h - 1) {
            res = crr_cost;
            break;
        }
        used[crr_y][crr_x] = true;
        rep(i, 4) {
            int nx = crr_x + dx[i], ny = crr_y + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (s[ny][nx] == '#') continue;
            q.push({-crr_cost, {nx, ny}});
        }

        rep(i, 4) {
            rep(j, 6) {
                int nx = crr_x + dw[i][j], ny = crr_y + dh[i][j];
                if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                q.push({-(crr_cost + 1), {nx, ny}});
            }
        }
    }
    cout << res << endl;
    return 0;
}