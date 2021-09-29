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
    ll a, b;
    cin >> a >> b;
    ll gcd = calc_gcd(a, b);
    ll max_v = (ll)1e18;
    max_v /= (a / gcd);

    if (max_v < b) {
        cout << "Large" << endl;
    } else {
        cout << (a / gcd) * b << endl;
    }
    return 0;
}