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

struct state {
    int x, y, dir;
} int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    rs--, cs--, rt--, ct--;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    deque<state> q;
    vector<vector<vector<ll>>> cost(h, vector<ll>(w, INF));
    cost[rs][cs] = -1;
    q.push({cs, rs, -1});
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

    while (!q.empty()) {
        auto crr = q.front();
        q.pop_front();
        if (crr.x == ct && crr.y == rt) break;
        rep(i, 4) {
            int next_x = crr.x + dx[i];
            int next_y = crr.y + dy[i];
            if (next_x < 0 || next_x >= w || next_y < 0 || next_y >= h) continue;
            if (s[next_y][next_x] == '#') continue;
            if (orient == (i + 2) % 4) continue;
            if (orient != i) next_cost++;
            if (next_cost > res[next_y][next_x]) continue;
            res[next_y][next_x] = next_cost;
            q.push({-next_cost, {{next_x, next_y}, i}});
        }
    }
    cout << res[rt][ct] << endl;
    return 0;
}