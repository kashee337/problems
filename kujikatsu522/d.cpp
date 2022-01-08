#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
    ll init_cost = 0;
    if (s[0][0] == '#' || s[h - 1][w - 1] == '#') {
        rep(i, h) {
            rep(j, w) {
                if (s[i][j] == '#')
                    s[i][j] = '.';
                else
                    s[i][j] = '#';
            }
        }
        init_cost++;
    }

    priority_queue<pair<ll, pair<pair<ll, ll>, bool>>> q;
    q.push({-init_cost, {{0, 0}, false}});
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};
    vector<vector<bool>> used(h, vector<bool>(w, false));
    while (!q.empty()) {
        ll cost = -q.top().first;
        ll x = q.top().second.first.first;
        ll y = q.top().second.first.second;
        bool status = q.top().second.second;
        q.pop();
        if (used[y][x]) continue;
        if (x == w - 1 && y == h - 1) {
            cout << cost << endl;
            return 0;
        }
        used[y][x] = true;
        char c = s[y][x];

        rep(i, 2) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;

            if (s[ny][nx] == c) {
                q.push({-cost, {{nx, ny}, status}});
            } else {
                if (status) {
                    q.push({-cost, {{nx, ny}, !status}});
                } else {
                    q.push({-(cost + 1), {{nx, ny}, !status}});
                }
            }
        }
    }

    return 0;
}