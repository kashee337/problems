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
struct edge {
    ll to, cost;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, r;
    cin >> n >> m >> r;
    vector<ll> R(r);
    rep(i, r) {
        cin >> R[i];
        R[i]--;
    }
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    rep(i, n) d[i][i] = 0;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                d[i][j] = d[i][j];
            }
        }
    }
    ll res = INF;
    sort(R.begin(), R.end());
    do {
        ll tmp = 0;
        rep(i, r - 1) { tmp += d[R[i]][R[i + 1]]; }
        res = min(res, tmp);
    } while (next_permutation(R.begin(), R.end()));
    cout << res << endl;
    return 0;
}