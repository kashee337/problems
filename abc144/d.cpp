#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
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
const double PI = 3.14159265358979323846;
bool check(double a, double b, double theta, double x) {
    double ret;
    if (a * tan(theta) <= b) {
        ret = a * a * b - a * a * a * tan(theta) / 2.0;
    } else {
        ret = b * b / tan(theta) * a / 2.0;
    }
    return ret < x;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    double a, b, x;
    cin >> a >> b >> x;
    double ok = PI / 2.0;
    double ng = 0;
    rep(i, 100000) {
        double mid = (ok + ng) / 2.0;
        if (check(a, b, mid, x))
            ok = mid;
        else
            ng = mid;
    }
    cout << fixed << setprecision(10) << ok / PI * 180 << endl;
    return 0;
}