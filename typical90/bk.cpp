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
    vector<vector<ll>> p(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> p[i][j];

    ll all_num = 1 << h;
    ll res = 0;
    rep(i, all_num) {
        if (i == 0) continue;
        vector<int> use;
        rep(row, h) {
            if ((i >> row) & 1) { use.pb(row); }
        }

        map<ll, ll> memo;
        rep(x, w) {
            bool ok = true;
            ll v = p[use[0]][x];
            for (int row : use) {
                if (p[row][x] != v) {
                    ok = false;
                    break;
                }
            }
            if (ok) memo[v] += use.size();
        }
        ll tmp = 0;
        for (auto v : memo) { tmp = max(tmp, v.second); }
        res = max(res, tmp);
    }

    cout << res << endl;
    return 0;
}