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
const long double PI = 3.14159265358979323846;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<ll, ll>> xy(n);
    rep(i, n) cin >> xy[i].first >> xy[i].second;
    long double res = -INF;
    vector<vector<long double>> theta(n);
    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            long double dx = xy[j].first - xy[i].first, dy = xy[j].second - xy[i].second;
            long double t = atan2l(dy, dx) * (180.0 / PI);
            if (t < 0) t = 360.0 + t;
            theta[i].pb(t);
        }
        sort(theta[i].begin(), theta[i].end());
    }

    rep(i, n) {
        for (auto t1 : theta[i]) {
            long double target = fmodl((t1 + 180.0), 360);
            int pos = lower_bound(theta[i].begin(), theta[i].end(), target) - theta[i].begin();
            int idx_0 = pos % theta[i].size();
            int idx_1 = (pos + theta[i].size() - 1) % theta[i].size();
            long double t2 =
                abs(target - theta[i][idx_0]) < abs(target - theta[i][idx_1]) ? theta[i][idx_0] : theta[i][idx_1];

            long double dt = abs(t1 - t2);
            long double t = min(dt, 360.0 - dt);
            if (res < t) res = t;
        }
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}
