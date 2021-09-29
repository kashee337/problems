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
    cin >> n;
    // vector<pair<int, int>> p(n);
    map<int, vector<int>> ys;
    map<int, vector<int>> xs;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        xs[x].pb(y);
        ys[y].pb(x);
    }
    ll res = 0;
    vector<int> uniq_x;
    for (auto x : xs) uniq_x.pb(x.first);
    int m = uniq_x.size();
    rep(i, m) {
        reps(j, m, i + 1) {
            for
        }
    }
    return 0;
}