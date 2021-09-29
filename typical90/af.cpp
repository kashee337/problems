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
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, n) {
        rep(j, n) { cin >> a[i][j]; }
    }
    ll m;
    cin >> m;
    map<pair<int, int>, int> bad;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        bad[{x, y}] = 1;
        bad[{y, x}] = 1;
    }

    vector<int> k(n);
    rep(i, n) k[i] = i;

    ll res = INF;
    do {
        ll tmp = 0;
        rep(i, n) {
            tmp += a[k[i]][i];
            if (i < n - 1 && bad[{k[i], k[i + 1]}] > 0) break;
            if (i == n - 1) res = min(res, tmp);
        }
    } while (next_permutation(k.begin(), k.end()));

    if (res == INF) res = -1;
    cout << res << endl;

    return 0;
}