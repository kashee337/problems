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
    int h, w, x, y;
    cin >> h >> w >> y >> x;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    x--, y--;
    ll res = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    rep(i, 4) {
        int cx = x;
        int cy = y;
        while (1) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) break;
            if (s[ny][nx] == '#') break;
            cx = nx;
            cy = ny;
            res++;
        }
    }
    if (s[y][x] == '.') res++;
    cout << res << endl;
    return 0;
}