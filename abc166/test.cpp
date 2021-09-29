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
    rep(i, h) { cin >> s[i]; }
    int sx, sy, gx, gy;
    rep(y, h) {
        rep(x, w) {
            if (s[y][x] == 's') {
                sx = x;
                sy = y;
            } else if (s[y][x] == 'g') {
                gx = x;
                gy = y;
            }
        }
    }
    stack<pair<int, int>> st;
    st.push({sx, sy});
    vector<vector<bool>> visit(h, vector<bool>(w, false));

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    while (!st.empty()) {
        auto v = st.top();
        st.pop();
        int crr_x = v.first;
        int crr_y = v.second;
        rep(i, 4) {
            int next_x = crr_x + dx[i];
            int next_y = crr_y + dy[i];
            if (next_x < 0 || next_x >= w || next_y < 0 || next_y >= h) continue;
            if (s[next_y][next_x] == '#') continue;
            if (visit[next_y][next_x]) continue;

            visit[next_y][next_x] = true;
            st.push({next_x, next_y});
        }
    }
    string res = visit[gy][gx] ? "Yes" : "No";
    cout << res << endl;
    return 0;
}