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
    ll n, m, q;
    cin >> n >> m >> q;
    vector<pair<ll, ll>> vw(n);
    rep(i, n) { cin >> vw[i].second >> vw[i].first; }
    sort(vw.begin(), vw.end(), greater<pair<ll, ll>>());

    vector<ll> x(m);
    rep(i, m) cin >> x[i];

    ll l, r;
    rep(i, q) {
        cin >> l >> r;
        l--, r--;
        ll res = 0;
        vector<bool> used(m, false);
        for (auto _vw : vw) {
            ll v = _vw.first;
            ll w = _vw.second;
            ll min_x = INF;
            ll idx = -1;
            rep(j, m) {
                if (used[j]) continue;
                if (j >= l && j <= r) continue;
                if (x[j] >= w) {
                    if (min_x > x[j]) {
                        min_x = x[j];
                        idx = j;
                    }
                }
            }
            if (idx == -1) continue;
            used[idx] = true;
            res += v;
        }
        cout << res << endl;
    }
    return 0;
}