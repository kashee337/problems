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
    int r, c;
    cin >> r >> c;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    sx--, sy--, gx--, gy--;
    vector<string> maze(r);
    rep(i, r) cin >> maze[i];
    queue<pair<pair<int, int>, int>> q;
    q.push({{sy, sx}, 0});

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        int cx, cy, cost;
        cy = v.first.first;
        cx = v.first.second;
        cost = v.second;
        rep(i, 4) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
        }
    }
    return 0;
}