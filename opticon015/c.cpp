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
    ll res = 0;
    ll l = 1, r = 2e9;
    while (l + 1LL < r) {
        ll mid = (l + r) / 2;
        ll v = mid * (1LL + mid);
        if (v <= 2 * (n + 1LL)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    res += (n - l) + 1LL;
    cout << res << endl;
    return 0;
}