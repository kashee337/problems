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
constexpr int MOD = 100000;
// constexpr int MOD = 5;
ll button(ll x) {
    string s = to_string(x);
    ll y = 0;
    for (auto c : s) { y += c - '0'; }
    return (x + y) % MOD;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    map<ll, ll> memo;
    ll x = n;
    memo[x] = 0;
    rep(i, k) {
        x = button(x);
        if (x == 0) break;
        if (memo.count(x)) {
            ll freq = (i + 1) - memo[x];
            ll _k = (k - (ll)(i + 1)) % freq;
            rep(j, _k) { x = button(x); }
            break;
        }
        memo[x] = i + 1;
    }

    cout << x << endl;
    return 0;
}