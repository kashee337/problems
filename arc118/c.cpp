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

ll calc_lcm(ll x, ll y) { return (x / calc_gcd(y, x % y)) * y; }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    set<ll> a;
    a.insert(2 * 3);
    a.insert(3 * 5);
    a.insert(5 * 2);
    ll v1 = 6, v2 = 15, v3 = 10;
    while (a.size() < n) {
        v1 += 6;
        v2 += 15;
        v3 += 10;
        if (a.size() < n && v1 <= 10000) a.insert(v1);
        if (a.size() < n && v2 <= 10000) a.insert(v2);
        if (a.size() < n && v3 <= 10000) a.insert(v3);
    }
    for (auto v : a) cout << v << endl;
    return 0;
}