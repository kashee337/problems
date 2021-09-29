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
    ll a, b, w;
    cin >> a >> b >> w;
    long double w_kg = 1000 * w;
    ll res_min = INF, res_max = -1;
    reps(i, w_kg + 1, 1) {
        long double n = w_kg / (long double)i;
        if (a <= n && n <= b) {
            res_min = res_min > i ? i : res_min;
            res_max = res_max < i ? i : res_max;
        }
    }
    if (res_max == -1)
        cout << "UNSATISFIABLE" << endl;
    else
        cout << res_min << " " << res_max << endl;
    return 0;
}