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
    vector<vector<ll>> a(h, vector<ll>(w));
    vector<vector<ll>> b(h, vector<ll>(w));
    rep(i, h) { rep(j, w) cin >> a[i][j]; }
    rep(i, h) { rep(j, w) cin >> b[i][j]; }
    rep(i, h) { rep(j, w) a[i][j] -= b[i][j]; }
    ll res = 0;
    rep(y, h - 1) {
        rep(x, w - 1) {
            ll v = -a[y][x];
            res += abs(v);
            rep(dy, 2) {
                rep(dx, 2) { a[y + dy][x + dx] += v; }
            }
        }
    }
    rep(i, h) {
        rep(j, w) if (a[i][j] != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    cout << res << endl;
    return 0;
}