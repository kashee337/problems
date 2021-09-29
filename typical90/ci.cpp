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
vector<vector<ll>> a;
int n, p, k;
bool solve_l(ll x) {
    vector<vector<ll>> dist(n, vector<ll>(n));
    rep(i, n) {
        rep(j, n) {
            if (a[i][j] == -1)
                dist[i][j] = x;
            else
                dist[i][j] = a[i][j];
        }
    }
    rep(k, n) {
        rep(i, n) {
            rep(j, n) { dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); }
        }
    }
    ll num = 0;
    rep(i, n) {
        reps(j, n, i + 1) {
            if (dist[i][j] <= p) num++;
        }
    }
    return num <= k;
}
bool solve_r(ll x) {
    vector<vector<ll>> dist(n, vector<ll>(n));
    rep(i, n) {
        rep(j, n) {
            if (a[i][j] == -1)
                dist[i][j] = x;
            else
                dist[i][j] = a[i][j];
        }
    }
    rep(k, n) {
        rep(i, n) {
            rep(j, n) { dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); }
        }
    }
    ll num = 0;
    rep(i, n) {
        reps(j, n, i + 1) {
            if (dist[i][j] <= p) num++;
        }
    }
    return num < k;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> p >> k;
    a.resize(n, vector<ll>(n));
    rep(i, n) { rep(j, n) cin >> a[i][j]; }

    ll l_low = 0, l_high = 1e9 + 1LL;
    ll r_low = 0, r_high = 1e9 + 1LL;
    while (l_low + 1 < l_high) {
        ll mid = (l_low + l_high) / 2;

        if (solve_l(mid)) {
            l_high = mid;
        } else {
            l_low = mid;
        }
    }
    while (r_low + 1 < r_high) {
        ll mid = (r_low + r_high) / 2;

        if (solve_r(mid)) {
            r_high = mid;
        } else {
            r_low = mid;
        }
    }
    if (r_low == (ll)1e9 && l_low != (ll)1e9)
        cout << "Infinity" << endl;
    else
        cout << r_low - l_low << endl;
    return 0;
}