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
#define CMAX 1010
int noinit = 1;
ll memo[CMAX][CMAX];
ll comb(ll a, ll b) {
    if (noinit) {
        rep(i, CMAX) rep(j, CMAX) memo[i][j] = -1;
        noinit = 0;
    }
    if (b == 0 || a == b) return 1;
    if (0 <= memo[a][b]) return memo[a][b];
    return memo[a][b] = comb(a - 1, b - 1) + comb(a - 1, b);
}
ll modPow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
    } else {
        ll bit = 0;
        while (n > 0) {
            bit++;
            n = n >> 1;
        }
        ll res = 0;
        rep(i, bit + 1) {
            res = res + comb(bit, i) * modPow(2, i, MOD) % MOD;
            res %= MOD;
        }
        cout << res << endl;
    }
    return 0;
}