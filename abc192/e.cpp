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
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    x--, y--;
    vector<vector<pair<ll, pair<ll, ll>>>> train(n);
    rep(i, m) {
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        a--, b--;
        train[a].pb({b, {t, k}});
        train[b].pb({a, {t, k}});
    }
    priority_queue<pair<ll, ll>> q;
    q.push({0, x});
    vector<ll> time(n, INF);
    while (!q.empty()) {
        auto v = q.top();
        q.pop();
        ll crr_t = -v.first;
        ll crr_city = v.second;
        if (time[crr_city] != INF) continue;
        time[crr_city] = crr_t;
        for (auto ctk : train[crr_city]) {
            ll next_city = ctk.first;
            ll t = ctk.second.first;
            ll k = ctk.second.second;
            ll dt = (k - crr_t % k) % k;
            ll next_t = crr_t + dt + t;
            q.push({-next_t, next_city});
        }
    }
    if (time[y] != INF)
        cout << time[y] << endl;
    else
        cout << -1 << endl;
    return 0;
}