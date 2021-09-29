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
    vector<vector<ll>> g(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
    }
    vector<vector<ll>> st(n);
    stack<ll> s;
    rep(i, n) {
        s.push(i);
        vector<bool> visited(n, false);
        while (!s.empty()) {
            int crr = s.top();
            s.pop();
            if (visited[crr]) continue;
            visited[crr] = true;
            st[i].pb(crr);
            for (int next : g[crr]) { s.push(next); }
        }
    }
    ll res = 0;
    rep(i, n) res += st[i].size();
    cout << res << endl;
    return 0;
}