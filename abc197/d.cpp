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
    ll n;
    cin >> n;
    ll x0, y0, x2, y2;
    cin >> x0 >> y0 >> x2 >> y2;
    long double theta = PI * (360 / (long double)n) / 180.0;
    long double ox = (x0 + x2) / 2.0, oy = (y0 + y2) / 2.0;
    long double a[2] = {x0 - ox, y0 - oy};
    long double next[2];
    next[0] = (a[0] * cosl(theta) - a[1] * sinl(theta));
    next[1] = (a[0] * sinl(theta) + a[1] * cosl(theta));
    cout << fixed << setprecision(10) << ox + next[0] << " " << oy + next[1] << endl;
    return 0;
}