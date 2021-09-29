#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> xs;
    map<ll, ll> seen;
    int cnt = 0;
    while (1) {
        if (seen.count(x)) break;
        xs.pb(x);
        seen[x] = cnt;
        x = x * x % m;
        cnt++;
    }
    ll idx = seen[x];
    ll res = 0;
    rep(i, idx) res += xs[i];
    if (idx != n) {
        ll loop_size = xs.size() - idx;
        ll _n = n - idx;
        ll m1 = _n / loop_size;
        ll m2 = _n % loop_size;
        ll tmp = 0;
        reps(i, xs.size(), idx) { tmp += xs[i]; }
        res += m1 * tmp;
        reps(i, idx + m2, idx) { res += xs[i]; }
    }
    cout << res << endl;
    return 0;
}