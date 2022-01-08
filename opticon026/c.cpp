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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> r, g, b;
    map<char, int> d;
    rep(i, 2 * n) {
        ll a;
        char c;
        cin >> a >> c;
        if (c == 'R') {
            r.pb(a);
        } else if (c == 'G') {
            g.pb(a);
        } else {
            b.pb(a);
        }
        d[c]++;
    }
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());

    if (r.size() % 2 == 0 && g.size() % 2 == 0 && b.size() % 2 == 0) {
        cout << 0 << endl;
    } else {
        if (r.size() % 2 == 0) {
            swap(r, b);
        } else if (g.size() % 2 == 0) {
            swap(g, b);
        }
        ll ans = 0;
        ll tmp = 0;
        rep(i, r.size()) {
            ll idx = lower_bound(b.begin(), b.end(), r[i]) - b.begin();
            if (idx == 0) { tmp = min(abs(r[i], b[idx])); }
        }
    }
    return 0;
}