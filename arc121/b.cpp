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
    ll n;
    cin >> n;
    vector<ll> r, g, b;
    rep(i, 2 * n) {
        ll a;
        char c;
        cin >> a >> c;
        if (c == 'R')
            r.pb(a);
        else if (c == 'G')
            g.pb(a);
        else
            b.pb(a);
    }
    ll res;
    if (r.size() % 2 == 0 && g.size() % 2 == 0 && b.size() % 2 == 0) {
        res = 0;
    } else {
        sort(r.begin(), r.end());
        sort(g.begin(), g.end());
        sort(b.begin(), b.end());
        ll rg = INF, gb = INF, rb = INF;
        if (r.size() % 2 == 0)
            swap(r, b);
        else if (g.size() % 2 == 0)
            swap(g, b);

        rep(i, r.size()) {
            int idx = lower_bound(g.begin(), g.end(), r[i]) - g.begin();

            if (idx < g.size()) rg = min(rg, abs(r[i] - g[idx]));
            if (idx > 0) { rg = min(rg, abs(r[i] - g[idx - 1])); }
        }

        rep(i, g.size()) {
            int idx = lower_bound(b.begin(), b.end(), g[i]) - b.begin();
            if (idx < b.size()) gb = min(gb, abs(g[i] - b[idx]));
            if (idx > 0) { gb = min(gb, abs(g[i] - b[idx - 1])); }
        }

        rep(i, r.size()) {
            int idx = lower_bound(b.begin(), b.end(), r[i]) - b.begin();
            if (idx < b.size()) rb = min(rb, abs(r[i] - b[idx]));
            if (idx > 0) { rb = min(rb, abs(r[i] - b[idx - 1])); }
        }

        res = min(rg, rb + gb);
    }
    cout << res << endl;
    return 0;
}