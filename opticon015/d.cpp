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
    vector<string> res(n, "");
    rep(i, n) cin >> b[i];
    rep(i, n) rep(j, m) res[i] += '0';
    rep(y, n - 1) {
        rep(x, m) {
            ll nx1 = x + 1, ny1 = y + 1, nx2 = x - 1, ny2 = y + 2;
            ll d0 = b[y][x] - '0';
            if (d0 == 0) continue;
            ll d1 = b[ny1][nx1] - '0';
            ll d2 = b[ny1][nx2] - '0';
            ll d3 = b[ny2][x] - '0';

            b[y][x] = '0';
            if (d0 <= d1 && d0 <= d2 && d0 <= d3) {
                b[ny1][nx1] = d1 - d0 + '0';
                b[ny1][nx2] = d2 - d0 + '0';
                b[ny2][x] = d3 - d0 + '0';
                res[ny1][x] = d0 + '0';
            }
        }
    }
    rep(i, n) {
        for (auto c : res[i]) cout << c;
        cout << endl;
    }
    return 0;
}