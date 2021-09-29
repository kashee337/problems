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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    rep(i, m) cin >> a[i];
    ll res = 0;
    if (m == n) {
        res = 0;
    } else {
        sort(a.begin(), a.end());
        vector<ll> margin;
        ll b = 0;
        rep(i, m) {
            margin.pb(a[i] - b - 1);
            b = a[i];
        }
        margin.pb(n - b);
        ll k = n;
        for (auto l : margin) {
            if (l > 0) k = min(l, k);
        }
        for (auto l : margin) { res += ceil(l / (double)k); }
    }
    cout << res << endl;
    return 0;
}