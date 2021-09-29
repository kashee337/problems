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
    ll n, m, t;
    cin >> n >> m >> t;
    ll battery = n;

    ll a = 0, b = 0;
    rep(i, m) {
        ll _a, _b;
        cin >> _a >> _b;
        battery -= _a - b;
        if (battery <= 0) { break; }
        battery += _b - _a;
        battery = min(battery, n);
        a = _a;
        b = _b;
    }

    battery -= t - b;
    if (battery > 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
