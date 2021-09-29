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
    ll h, w;
    cin >> h >> w;
    int sx, sy, gx, gy;
    cin >> sy >> sx >> gy >> gx;
    sx--, sy--, gx--, gy--;
    vector<string> cc(h);
    rep(i, h) cin >> cc[i];
    queue<pair<pair<int, int>, int>> q;
    q.push({{sx, sy}, 0});
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    vector<vector<bool>> used(h, vector<bool>(w, false));
    while (!q.empty()) {
        auto crr = q.front();
        q.pop();
        int cx = crr.first.first;
        int cy = crr.first.second;
        int cost = crr.second;
        if (used[cy][cx]) continue;
        used[cy][cx] = true;
        if (cx == gx && cy == gy) {
            cout << cost << endl;
            return 0;
        }
        rep(i, 4) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (cc[ny][nx] == '#') continue;
            q.push({{nx, ny}, cost + 1});
        }
    }
    return 0;
}