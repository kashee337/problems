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
    vector<vector<int>> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> res(n, -1);
    queue<pair<int, int>> q;
    q.push({0, -1});
    while (!q.empty()) {
        int crr = q.front().first;
        int from = q.front().second;
        q.pop();
        if (res[crr] != -1) continue;
        res[crr] = from + 1;
        for (int to : g[crr]) { q.push({to, crr}); }
    }
    cout << "Yes" << endl;
    reps(i, n, 1) cout << res[i] << endl;
    return 0;
}