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
    ll t, l, x, y;
    cin >> t >> l >> x >> y;
    ll q;
    cin >> q;
    rep(i, q) {
        ll e;
        cin >> e;
        long double theta = 2 * PI * (e % t) / (long double)t;
        long double crr_x = 0;
        long double crr_y = -(l / 2.0) * sinl(theta);
        long double crr_z = (l / 2.0) + (l / 2.0) * sinl(theta - PI / 2);
        // cout << crr_x << " " << crr_y << " " << crr_z << endl;
        long double dx = x - crr_x, dy = y - crr_y, dz = crr_z;
        long double dxdy = sqrtl(dx * dx + dy * dy);
        long double res = atan2(dz, dxdy) * (180.0 / PI);
        cout << fixed << setprecision(10) << res << endl;
    }
    return 0;
}