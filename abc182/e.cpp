#include <algorithm>
#include <cmath>
#include <deque>
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
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    vector<vector<int>> field_y(h, vector<int>(w, 0)), field_x = field_y;
    rep(i, n) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    rep(i, m) {
        cin >> c[i] >> d[i];
        c[i]--, d[i]--;
        field_y[c[i]][d[i]] = -1;
        field_x[c[i]][d[i]] = -1;
    }

    //縦
    rep(i, n) {
        int x = b[i];
        int y = a[i];
        if (field_y[y][x] > 0) continue;
        field_y[y][x] = 1;
        int ny = y - 1;
        while (1) {
            if (ny < 0 || field_y[ny][x] < 0) break;
            field_y[ny--][x] = 1;
        }
        ny = y + 1;
        while (1) {
            if (ny >= h || field_y[ny][x] < 0) break;
            field_y[ny++][x] = 1;
        }
    }
    //横
    rep(i, n) {
        int x = b[i];
        int y = a[i];
        if (field_x[y][x] > 0) continue;
        field_x[y][x] = 1;
        int nx = x - 1;
        while (1) {
            if (nx < 0 || field_x[y][nx] < 0) break;
            field_x[y][nx--] = 1;
        }
        nx = x + 1;
        while (1) {
            if (nx >= w || field_x[y][nx] < 0) break;
            field_x[y][nx++] = 1;
        }
    }
    int res = 0;
    rep(i, h) {
        rep(j, w) {
            if (field_x[i][j] > 0 || field_y[i][j] > 0) res++;
        }
    }
    cout << res << endl;
    return 0;
}