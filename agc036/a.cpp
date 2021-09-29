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
constexpr double PI = 3.14159265358979323846;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll s;
    cin >> s;
    ll x1, y1, x2, y2, x3, y3;
    x1 = 0;
    y1 = 0;
    x2 = (ll)1e9;
    y2 = 1;
    y3 = ceil(s / (long double)x2);
    x3 = x2 * y3 - s;

    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;

    return 0;
}