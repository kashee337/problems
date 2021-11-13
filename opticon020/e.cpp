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
using Pt = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    map<char, vector<Pt>> warp;
    rep(i, h) {
        rep(j, w) {
            if (a[i][j] != '#' && a[i][j] != '.') { warp[a[i][j]].pb({j, i}); }
        }
    }

    queue<pair<Pt, ll>> q;
    ll sx = warp['S'][0].first;
    ll sy = warp['S'][0].second;
    ll gx = warp['G'][0].first;
    ll gy = warp['G'][0].second;
    q.push({{sx, sy}, 0});
    vector<vector<ll>> cost_map(h, vector<ll>(w, -1));

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    while (!q.empty()) {
        ll cx = q.front().first.first;
        ll cy = q.front().first.second;
        ll cost = q.front().second;
        q.pop();
        if (cost_map[cy][cx] >= 0) continue;
        cost_map[cy][cx] = cost;
        if (cx == gx && cy == gy) break;

        rep(i, 4) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (a[ny][nx] == '#') continue;
            q.push({{nx, ny}, cost + 1});
        }
        ll c = a[cy][cx];
        if (c != '.') {
            ll nx = -1, ny = -1;
            for (auto p : warp[a[cy][cx]]) {
                if (p.first != cx || p.second != cy) {
                    nx = p.first;
                    ny = p.second;
                }
            }
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (cost_map[ny][nx] < 0) { q.push({{nx, ny}, cost + 1}); }
        }
    }
    cout << cost_map[gy][gx] << endl;
    return 0;
}