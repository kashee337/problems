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
ll modPow(ll a, ll _n, ll mod) {
    ll res = 1;
    ll n = _n;
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
    ll a, b, c;
    cin >> a >> b >> c;
    map<ll, int> memo;
    ll _a = a % 10;
    ll tmp = _a;
    vector<ll> cnt;
    while (1) {
        if (memo.count(tmp % 10)) { break; }
        memo[tmp % 10] = 1;
        cnt.pb(tmp % 10);
        tmp *= _a;
    }
    ll mod = cnt.size();
    ll idx = modPow(b, c, mod) - 1LL;
    if (idx == -1) idx = mod - 1;
    cout << cnt[idx] << endl;
    return 0;
}