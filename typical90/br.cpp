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
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i, n) { cin >> x[i] >> y[i]; }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    long double med_x, med_y;
    if (n % 2) {
        med_x = x[(n - 1) / 2];
        med_y = y[(n - 1) / 2];
    } else if (n == 1) {
        med_x = x[0];
        med_y = y[0];
    } else {
        med_x = (long double)(x[n / 2] + x[n / 2 - 1]) / 2;
        med_y = (long double)(y[n / 2] + y[n / 2 - 1]) / 2;
    }
    long double res = 0;
    rep(i, n) { res += abs(med_x - (long double)x[i]) + abs(med_y - (long double)y[i]); }
    cout << (ll)res << endl;
    return 0;
}