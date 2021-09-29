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
constexpr int MOD = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    map<ll, map<char, ll>> memo;
    rep(i, h) { rep(j, w) memo[i + j][s[i][j]]++; }
    ll res = 1;
    for (auto v : memo) {
        if (v.second['R'] > 0 && v.second['B'] > 0) {
            res = 0;
            break;
        } else if (v.second['R'] == 0 && v.second['B'] == 0 && v.second['.'] > 0) {
            res *= 2;
            res %= MOD;
        }
    }
    cout << res << endl;

    return 0;
}