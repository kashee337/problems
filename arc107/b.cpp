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

ll solve(ll n, ll v) {
    if (v <= n) return v - 1;
    return (v - 1) - (v - n - 1) * 2;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    k = abs(k);
    ll res = 0;
    reps(ab, 2 * n + 1, 2) {
        ll cd = ab - k;
        if (cd < 2) continue;
        ll ab_num = ab <= n + 1 ? (ab - 1) : (2 * n + 1 - ab);
        ll cd_num = cd <= n + 1 ? (cd - 1) : (2 * n + 1 - cd);
        res += ab_num * cd_num;
    }
    cout << res << endl;
    return 0;
}