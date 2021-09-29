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
    vector<vector<pair<ll, ll>>> g(n);
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb({b, c});
        g[b].pb({a, c});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    vector<bool> visited(n, false);
    vector<ll> res_0(n, 0);
    q.push({0, 0});
    while (!q.empty()) {
        ll t = q.top().first;
        ll crr = q.top().second;
        q.pop();
        if (visited[crr]) continue;
        visited[crr] = true;
        res_0[crr] = t;
        for (auto v : g[crr]) {
            ll next = v.first;
            ll c = v.second;
            q.push({t + c, next});
        }
    }

    vector<ll> res_1(n, 0);
    visited.assign(n, false);
    q.push({0, n - 1});
    while (!q.empty()) {
        ll t = q.top().first;
        ll crr = q.top().second;
        q.pop();
        if (visited[crr]) continue;
        visited[crr] = true;
        res_1[crr] = t;
        for (auto v : g[crr]) {
            ll next = v.first;
            ll c = v.second;
            q.push({t + c, next});
        }
    }
    rep(i, n) { cout << res_0[i] + res_1[i] << endl; }
    return 0;
}