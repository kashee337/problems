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
    vector<ll> a(m), b(m);
    vector<vector<ll>> g(n);
    bool ok = true;
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        if (find(g[b[i]].begin(), g[b[i]].end(), a[i]) != g[b[i]].end()) { ok = false; }
        g[a[i]].pb(b[i]);
    }
    if (ok) {
        vector<int> indeg(n, 0);
        rep(i, n) {
            for (auto v : g[i]) indeg[v]++;
        }
        priority_queue<int> q;
        rep(i, n) {
            if (indeg[i] == 0) q.push(-i);
        }
        vector<int> res;
        while (!q.empty()) {
            auto now = -q.top();
            q.pop();
            for (auto next : g[now]) {
                indeg[next]--;
                if (indeg[next] == 0) q.push(-next);
            }
            res.push_back(now);
        }
        for (int p : res) cout << p + 1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}