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
    ll dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    vector<vector<bool>> used(h, vector<bool>(w, false));
    rep(y, h) {
        rep(x, w) {
            // vector<ll> idx;
            // ll bc;
            // if (a[y][x] % 2 == 1)
            //     bc = 1;
            // else
            //     bc = 2;
            // rep(i, 4) {
            //     ll nx = dx[i] + x, ny = dy[i] + y;
            //     if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            //     if (used[ny][nx]) continue;
            //     if (a[ny][nx] % 2 == 1) idx.pb(i);
            //     if (idx.size() == bc) break;
            // }
            // if (idx.size() == bc) {
            //     for (auto i : idx) {
            //         ll nx = dx[i] + x, ny = dy[i] + y;
            //         a[y][x]++;
            //         a[ny][nx]--;
            //         res.pb({{ny + 1, nx + 1}, {y + 1, x + 1}});
            //         used[ny][nx] = true;
            //     }
            // }
            bool ok = false;
            rep(i, 4) {
                ll nx = dx[i] + x, ny = dy[i] + y;
                if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
                if (used[ny][nx]) continue;
                if (a[ny][nx] % 2 == 1) {
                    a[ny][nx]++;
                    a[y][x]--;
                    used[y][x] = true;
                    ok = true;
                    break;
                }
                if (ok) {
                    int nx = x + 1, ny = y;
                    if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
                }
            }
        }
    }
    cout << res.size() << endl;
    for (auto p : res) {
        cout << p.first.first << " " << p.first.second << " " << p.second.first << " " << p.second.second << endl;
    }
    return 0;
}