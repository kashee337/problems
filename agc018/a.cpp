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
ll calc_gcd(ll x, ll y) {
    if (y == 0) return x;
    return calc_gcd(y, x % y);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll gcd = 0;
    rep(i, n) {
        cin >> a[i];
        gcd = calc_gcd(a[i], gcd);
    }
    bool ok = false;
    ll v = *max_element(a.begin(), a.end());
    if (v >= k && (v - k) % gcd == 0) ok = true;
    string res = ok ? "POSSIBLE" : "IMPOSSIBLE";
    cout << res << endl;
    return 0;
}