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
ll dp_a[20][2][2], dp_b[20][2][2];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    dp_a[0][0][0] = 1;
    dp_b[0][0][0] = 1;
    rep(i, a.size()) {
        int d = a[i] - '0';
        rep(small, 2) {
            ll r = small ? 10 : d + 1;
            rep(k, r) {
                dp_a[i + 1][small || k < d][k == 4 || k == 9] += dp_a[i][small][0];
                dp_a[i + 1][small || k < d][1] += dp_a[i][small][1];
            }
        }
    }
    rep(i, b.size()) {
        int d = b[i] - '0';
        rep(small, 2) {
            ll r = small ? 10 : d + 1;
            rep(k, r) {
                dp_b[i + 1][small || k < d][k == 4 || k == 9] += dp_b[i][small][0];
                dp_b[i + 1][small || k < d][1] += dp_b[i][small][1];
            }
        }
    }
    ll res_b = dp_b[b.size()][0][1] + dp_b[b.size()][1][1];
    ll res_a = dp_a[a.size()][1][1];
    cout << res_b - res_a << endl;
    return 0;
}