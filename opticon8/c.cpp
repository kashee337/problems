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
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(y, h) rep(x, w) cin >> a[y][x];

    vector<pair<pair<ll, ll>, pair<ll, ll>>> res;
    rep(y, h) {
        rep(x, w) {
            int nx = x, ny = y;
            int crr_x;
            if (y % 2 == 0) {
                crr_x = x;
                if (x == w - 1) {
                    ny++;
                } else {
                    nx++;
                }
            } else {
                crr_x = w - 1 - x;
                nx = crr_x;
                if (crr_x == 0) {
                    ny++;
                } else {
                    nx--;
                }
            }
            if (ny == h) break;
            if (a[y][crr_x] % 2 == 1) {
                a[y][crr_x]--;
                a[ny][nx]++;
                res.pb({{y + 1, crr_x + 1}, {ny + 1, nx + 1}});
            }
        }
    }
    cout << res.size() << endl;
    for (auto p : res) {
        cout << p.first.first << " " << p.first.second << " " << p.second.first << " " << p.second.second << endl;
    }
    return 0;
}