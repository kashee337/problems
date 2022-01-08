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
    ll n;
    cin >> n;
    ll m = to_string(n).size();
    ll res = 0;
    reps(k, m + 1, 1) {
        ll base = 0;
        rep(i, k) { base = base * 10 + 1LL; }

        ll num_l = base;
        ll num_r = base + 1LL;
        while (num_r <= n) {
            res += num_r - num_l;
            num_l *= 10;
            num_r *= 10;
        }
        if (num_l <= n) res += n - num_l + 1LL;
    }
    cout << res << endl;
    return 0;
}