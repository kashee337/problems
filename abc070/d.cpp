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
    vector<vector<pair<ll, ll>>> g(n);
    rep(i, n - 1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb({c, b});
        g[b].pb({c, a});
    }
    ll q, k;
    cin >> q >> k;
    k--;
    vector<ll> min_path(n, INF);
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, k});
    while (!pq.empty()) {
        ll cost = pq.top().first;
        ll crr = pq.top().second;
        pq.pop();
        if (min_path[crr] < cost) continue;
        min_path[crr] = cost;
        for (auto v : g[crr]) {
            ll c = v.first;
            ll next = v.second;
            pq.push({cost + c, next});
        }
    }
    vector<ll> res;
    rep(i, q) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        res.pb(min_path[x] + min_path[y]);
    }
    for (ll v : res) cout << v << endl;
    return 0;
}