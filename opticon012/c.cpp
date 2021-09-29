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
vector<string> a;
int h, w;

ll ds() {
    priority_queue<pair<ll, pair<int, int>>> q;
    rep(y, h) {
        rep(x, w) {
            if (a[y][x] == '#') { q.push({0, {x, y}}); }
        }
    }

    vector<vector<ll>> memo(h, vector<ll>(w, INF));
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    vector<vector<bool>> used(h, vector<bool>(w, false));
    while (!q.empty()) {
        auto data = q.top();
        q.pop();
        ll crr_d = -data.first;
        int crr_x = data.second.first;
        int crr_y = data.second.second;
        if (used[crr_y][crr_x]) continue;
        used[crr_y][crr_x] = true;
        memo[crr_y][crr_x] = crr_d;
        rep(i, 4) {
            int nx = crr_x + dx[i];
            int ny = crr_y + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (a[ny][nx] == '#') continue;
            q.push({-(crr_d + 1LL), {nx, ny}});
        }
    }
    ll res = -1;
    rep(y, h) {
        rep(x, w) { res = max(res, memo[y][x]); }
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    a.resize(h);
    rep(i, h) cin >> a[i];
    ll res = ds();

    cout << res << endl;
    return 0;
}