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
    int n;
    int m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    ll cost = 0;
    map<int, int> memo;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb({b, c});
        g[b].pb({a, c});
        cost += c;
        memo[c]++;
    }
    priority_queue<pair<int, int>> pq;
    vector<bool> used(n, false);
    pq.push({0, 0});
    while (!pq.empty()) {
        ll c = -pq.top().first;
        ll crr = pq.top().second;
        pq.pop();
        if (used[crr]) continue;
        cost -= c;
        memo[c]--;
        used[crr] = true;
        for (auto v : g[crr]) {
            int next = v.first;
            pq.push({-v.second, v.first});
        }
    }
    for (auto v : memo) {
        if (v.first < 0) cost -= v.first * v.second;
    }
    cout << cost << endl;
    return 0;
}