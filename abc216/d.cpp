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
    vector<vector<int>> c(m);
    map<int, vector<pair<int, int>>> memo;
    rep(i, m) {
        int k;
        cin >> k;
        rep(j, k) {
            int v;
            cin >> v;
            c[i].pb(v);
            memo[v].pb({i, j + 1});
        }
    }

    string res = "Yes";
    for (auto v : memo) {
        if (v.second[0].first == v.second[1].first) res = "No";
    }
    rep(i, m) {
        map<int, int> d;
        for (int v : c[i]) {
            if (memo[v][0].first == i) {
                int idx = memo[v][1].first;
                int depth = memo[v][1].second;
                if (d[idx] > depth) { res = "No"; }
                d[idx] = depth;
            }
        }
    }
    cout << res << endl;
    return 0;
}
