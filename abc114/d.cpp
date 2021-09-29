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
ll get_divisor(ll n) {
    vector<ll> div;
    reps(i, sqrt(n) + 1, 1) {
        if (n % i == 0) {
            div.pb(i);
            div.pb(n / i);
        }
    }
    return div.size();
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> div_num(n);
    reps(i, n, 1) { div_num[i] = get_divisor(i); }
    ll res = 0;
    for (auto v : div_num) { res += v; }
    cout << res << endl;
    return 0;
}