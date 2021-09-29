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
    ll n, q;
    cin >> n >> q;
    vector<ll> xs(n), ys(n);
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        xs[i] = x - y;
        ys[i] = x + y;
    }
    ll min_x = *min_element(xs.begin(), xs.end());
    ll max_x = *max_element(xs.begin(), xs.end());
    ll min_y = *min_element(ys.begin(), ys.end());
    ll max_y = *max_element(ys.begin(), ys.end());
    rep(i, q) {
        int j;
        cin >> j;
        j--;
        ll res;
        res = max(max(abs(xs[j] - min_x), abs(xs[j] - max_x)), max(abs(ys[j] - min_y), abs(ys[j] - max_y)));
        cout << res << endl;
    }
    return 0;
}