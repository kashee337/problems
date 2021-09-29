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
    vector<ll> a(n);
    rep(i, n) { cin >> a[i]; }
    ll res = 0;
    vector<vector<ll>> min_val(n, vector<ll>(n, INF));
    rep(i, n) {
        reps(j, n, i) {
            if (i == j) {
                min_val[i][j] = a[i];
            } else {
                min_val[i][j] = min(min_val[i][j - 1], a[j]);
            }
        }
    }

    rep(i, n) {
        reps(j, n, i) {
            if (i == j) {
                res = max(res, min_val[i][j]);
            } else {
                res = max(res, min_val[i][j] * (j - i + 1));
            }
        }
    }
    cout << res << endl;
    return 0;
}
