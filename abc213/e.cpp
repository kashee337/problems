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

    priority_queue<pair<ll, pair<ll, ll>>> q;
    q.push({0, {0, 0}});
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    vector<vector<ll>> dp(h, vector<ll>(w, INF));
    while (!q.empty()) {
        ll cost = -q.top().first;
        ll x = q.top().second.first;
        ll y = q.top().second.second;
        q.pop();
        if (dp[y][x] <= cost) continue;
        dp[y][x] = cost;
        if (y == h - 1 && x == w - 1) {
            break;
            break;
        }
        rep(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;

            if (s[ny][nx] == '#') {
                if (i % 2 == 0) {
                    rep(j, 2) {
                        reps(k, 2, -1) {
                            int nnx = nx + j;
                            int nny = ny + k;
                            if (nnx < 0 || nnx >= w || nny < 0 || nny >= h) continue;
                            q.push({-(cost + 1), {nnx, nny}});
                        }
                    }
                } else {
                    reps(j, 2, -1) {
                        rep(k, 2) {
                            int nnx = nx + j;
                            int nny = ny + k;
                            if (nnx < 0 || nnx >= w || nny < 0 || nny >= h) continue;
                            q.push({-(cost + 1), {nnx, nny}});
                        }
                    }
                }

            } else if (s[ny][nx] == '.') {
                q.push({-cost, {nx, ny}});
            }
        }
    }
    cout << dp[h - 1][w - 1] << endl;
    return 0;
}