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

    rep(i, h) { rep(j, w) cin >> a[i][j]; }
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    vector<pair<pair<int, int>, pair<int, int>>> res;
    vector<vector<bool>> use(h, vector<bool>(w, false));
    bool ok = true;
    // 奇数枚なら移動させた方が良い
    // 移動させる先は
    while (ok) {
        ok = false;
        rep(y, h) {
            rep(x, w) {
                if (use[y][x]) continue;
                if (a[y][x] % 2 == 1) {
                    rep(k, 4) {
                        int nx = x - dx[k];
                        int ny = y - dy[k];
                        if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;

                        if (a[ny][nx] % 2 == 1) {
                            ok = true;
                            a[ny][nx] += 1;
                            a[y][x] -= 1;
                            res.pb({{x + 1, y + 1}, {nx + 1, ny + 1}});
                            use[y][x] = true;
                            break;
                        }
                    }
                } else {
                    vector<pair<int, int>> tmp;
                    rep(k, 4) {
                        int nx = x - dx[k];
                        int ny = y - dy[k];
                        if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                        if (use[ny][nx]) continue;

                        if (a[ny][nx] % 2 == 1) { tmp.pb({nx, ny}); }
                    }
                    if (tmp.size() >= 2) {
                        rep(l, 2) {
                            int nx = tmp[l].first;
                            int ny = tmp[l].second;
                            res.pb({{x + 1, y + 1}, {nx + 1, ny + 1}});
                            ok = true;
                            a[ny][nx] -= 1;
                            a[y][x] += 1;
                            use[ny][nx] = true;
                        }
                    }
                }
            }
        }
    }
    cout << res.size() << endl;
    for (auto v : res) {
        cout << v.first.first << " " << v.first.second << " " << v.second.first << " " << v.second.second << endl;
    }
    return 0;
}