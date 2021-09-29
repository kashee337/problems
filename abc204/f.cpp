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

ll tri_search(ll d, ll t) {
    ll left = t;
    ll right = d + 1LL;
    while (left + 2 < right) {
        ll mid_l = left * 2.0 / 3.0 + right / 3.0;
        ll mid_r = left / 3.0 + right * 2.0 / 3.0;
        if (floor(d / (mid_l + 1)) + mid_l < floor(d / (mid_r + 1)) + mid_r) {
            right = mid_r;
        } else {
            left = mid_l;
        }
    }
    // if (floor(d / (left + 1)) + left < floor(d / (left + 1 + 1) + left + 1))
    //     return left;
    // else
    //     return left + 1;
    return left + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, pair<ll, ll>>>> g(n);

    rep(i, m) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--;
        g[a].pb({b, {c, d}});
        if (a == b) continue;
        g[b].pb({a, {c, d}});
    }

    priority_queue<pair<ll, ll>> q;
    q.push({0, 0});

    vector<ll> visited(n, INF);
    ll res = -1;
    while (!q.empty()) {
        ll crr_t = -q.top().first;
        ll crr_v = q.top().second;
        q.pop();
        if (visited[crr_v] <= crr_t) continue;
        visited[crr_v] = crr_t;
        if (crr_v == n - 1) {
            res = crr_t;
            break;
        }
        for (auto next : g[crr_v]) {
            ll next_v = next.first;
            ll c = next.second.first;
            ll d = next.second.second;
            ll t = crr_t > d / 2 ? crr_t : tri_search(d, crr_t);
            ll next_t = t + c + floor(d / (t + 1));
            q.push({-next_t, next_v});
        }
    }
    cout << res << endl;
    return 0;
}