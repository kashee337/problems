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
    vector<string> s(n), t(n);

    rep(i, n) cin >> s[i];
    rep(i, n) cin >> t[i];
    map<char, vector<pair<int, int>>> ps;
    map<char, vector<pair<int, int>>> pt;

    rep(i, n) { rep(j, n) ps[s[i][j]].pb({i, j}); }
    rep(i, n) { rep(j, n) pt[t[i][j]].pb({i, j}); }
    if (ps['.'].size() > ps['#'].size()) {
        char c = '#';
        int m = ps['#'].size();
        vector<pair<int, int>> vs;
        rep(i, m) {
            reps(j, m, i + 1) {
                int dx = ps[c][j].first - ps[c][i].first;
                int dy = ps[c][j].second - ps[c][i].second;
                vs.pb({dx, dy});
            }
        }
        int ks = 1;

    } else {
        char c = '.';
    }
    cout << "No" << endl;
    return 0;
}
