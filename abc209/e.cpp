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
map<string, ll> depth_max, depth_min;
map<string, map<string, ll>> g;
ll dfs(string crr, ll d) {
    if (depth_max.count(crr)) return depth_max[crr];
    if (g[crr].count(crr)) return INF;
    for (auto next : g[crr]) {
        string ss = next.first;
        ll v = dfs(ss, d + 1) - d;
        depth_max[crr] = max(depth_max[crr], v);
        depth_min[crr] = min(depth_min[crr], v);
    }
    return d + depth_max[crr];
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) {
        cin >> s[i];
        string s1 = s[i].substr(0, 3);
        string s2 = s[i].substr(s[i].size() - 3);
        g[s1][s2]++;
    }
    rep(i, n) {
        string s1 = s[i].substr(0, 3);
        dfs(s1, 0);
    }
    return 0;
}