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
vector<ll> p_num, pb_num;

ll dfs(int level, ll x, ll val) {
    if (level < 0) return val;
    if (level == 0 and x > 0) return val + 1;
    if (x > 1) {
        ll mid = (pb_num[level] - 1) / 2;
        if (x > mid) {
            val = dfs(level - 1, x - mid - 1, val + (p_num[level] - 1) / 2 + 1);
        } else {
            val = dfs(level - 1, x - 1, val);
        }
    }
    return val;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, x;
    cin >> n >> x;
    p_num.pb(1);
    pb_num.pb(1);
    rep(i, n) {
        p_num.pb(1 + 2 * p_num[i]);
        pb_num.pb(3 + 2 * pb_num[i]);
    }

    cout << dfs(n, x, 0) << endl;
    return 0;
}