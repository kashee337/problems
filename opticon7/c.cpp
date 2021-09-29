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
    ll n, m;
    cin >> n >> m;
    vector<string> b(n);
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> res(n, vector<ll>(m, 0));
    rep(i, n) { cin >> b[i]; }
    rep(i, n) {
        rep(j, m) { a[i][j] = b[i][j] - '0'; }
    }
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    rep(i, n - 1) {
        rep(j, m - 1) {
            ll v = a[i][j];
            if (v > 0) {
                rep(k, 4) {
                    int nx = dx[k] + i + 1;
                    int ny = dy[k] + j;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }
                    v = min(a[nx][ny], v);
                }
                rep(k, 4) {
                    int nx = dx[k] + i + 1;
                    int ny = dy[k] + j;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }
                    a[nx][ny] -= v;
                }
                res[i + 1][j] += v;
            }
        }
    }

    rep(i, n) {
        rep(j, m) { cout << res[i][j]; }
        cout << endl;
    }
    return 0;
}
