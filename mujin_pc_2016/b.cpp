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
    vector<ll> l(3);
    cin >> l[0] >> l[1] >> l[2];
    sort(l.begin(), l.end());
    long double r_max = l[0] + l[1] + l[2];
    long double r_min;
    if (l[0] + l[1] >= l[2]) {
        r_min = 0;
    } else {
        r_min = l[2] - l[0] - l[1];
    }

    long double res = r_max * r_max * PI - r_min * r_min * PI;
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}