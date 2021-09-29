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

long double calc_len(long double x1, long double y1, long double x2, long double y2) {
    long double dx = (x2 - x1) * (x2 - x1);
    long double dy = (y2 - y1) * (y2 - y1);
    return sqrtl(dx + dy);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    long double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    long double a = calc_len(xa, ya, xb, yb);
    long double b = calc_len(xa, ya, xc, yc);
    long double c = calc_len(xc, yc, xb, yb);
    long double theta = acosl((b * b + c * c - a * a) / (2 * b * c));
    long double res = (1 / (long double)2) * c * b * sin(theta);
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}