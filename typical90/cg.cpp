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
    ll k;
    cin >> k;
    auto _div = get_divisor(k);
    vector<ll> div(_div.begin(), _div.end());
    ll res = 0;
    rrep(i, div.size()) {
        ll c = div[i];
        ll ab = k / c;
        auto _div2 = get_divisor(ab);
        vector<ll> div2(_div2.begin(), _div2.end());
        rep(j, div2.size()) {
            ll a = div2[j];
            ll b = ab / a;
            if (a <= b && b <= c) res++;
        }
    }
    cout << res << endl;
    return 0;
}