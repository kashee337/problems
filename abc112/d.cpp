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
set<ll> get_divisor(ll n) {
    set<ll> div;
    reps(i, sqrt(n) + 1, 1) {
        if (n % i == 0) {
            div.insert(i);
            div.insert(n / i);
        }
    }
    return div;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll res = 1;
    auto div = get_divisor(m);
    for (auto d : div) {
        if (n * d <= m) res = max(res, d);
    }
    cout << res << endl;
    return 0;
}