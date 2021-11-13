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
    ll n, m;
    cin >> n >> m;
    vector<ll> indeg(n, 0);
    map<ll, vector<ll>> g;
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        indeg[b]++;
    }
    priority_queue<ll> pq;
    rep(i, n) {
        if (indeg[i] == 0) pq.push(-i);
    }
    vector<ll> res;
    while (!pq.empty()) {
        ll v = -pq.top();
        pq.pop();

        for (auto u : g[v]) {
            indeg[u]--;
            if (indeg[u] == 0) pq.push(-u);
        }
        res.pb(v);
    }
    if (res.size() == n) {
        for (auto v : res) { cout << v + 1 << " "; }
    } else {
        cout << -1;
    }
    return 0;
}