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
    vector<vector<pair<ll, ll>>> road(n);
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        road[a].pb({-c, b});
    }

    rep(i, n) {
        ll res;
        priority_queue<pair<ll, ll>> q;

        for (auto v : road[i]) {
            if (v.first == i) {
                res = v.first;
            } else {
                q.push(v);
            }
        }
        vector<ll> use(n, -INF);
        while (!q.empty()) {
            auto v = q.top();
            q.pop();
            ll crr = v.second;
            ll cost = v.first;
            if (use[crr] > -INF) continue;
            use[crr] = cost;
            for (auto next : road[crr]) {
                if (next.second == crr) continue;
                if (use[next.second] > -INF) continue;
                q.push({next.first + cost, next.second});
            }
        }
        res = -use[i];
        if (res == INF) res = -1;
        cout << res << endl;
    }
    return 0;
}