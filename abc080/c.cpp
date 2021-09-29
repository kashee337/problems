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
    int n;
    cin >> n;
    vector<vector<int>> f(n, vector<int>(10));
    rep(i, n) { rep(j, 10) cin >> f[i][j]; }
    vector<vector<ll>> p(n, vector<ll>(11));
    rep(i, n) { rep(j, 11) cin >> p[i][j]; }

    ll res = -INF;
    ll all = 1 << 10;
    reps(bit, all, 1) {
        map<int, int> count;
        rep(t, 10) {
            if (bit >> t & 1) {
                rep(i, n) {
                    if (f[i][t]) { count[i]++; }
                }
            }
        }
        ll tmp = 0;
        rep(i, n) { tmp += p[i][count[i]]; }
        res = max(res, tmp);
    }
    cout << res << endl;
    return 0;
}