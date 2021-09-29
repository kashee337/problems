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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<vector<int>> cut(h, vector<int>(w, 0));
    queue<int> q;
    reps(i, k + 1, 1) q.push(i);

    function<void(int, int, int, int)> solve = [&](int lx, int ly, int rx, int ry) {
        vector<pair<int, int>> strawberry;
        reps(y, ry, ly) {
            reps(x, rx, lx) {
                if (s[y][x] == '#') { strawberry.pb({x, y}); }
            }
        }
        int n = strawberry.size();
        if (n == 1) {
            int c = q.front();
            q.pop();
            reps(y, ry, ly) {
                reps(x, rx, lx) { cut[y][x] = c; }
            }
        } else {
            auto s1 = strawberry[0];
            auto s2 = strawberry[1];
            if (s1.first == s2.first) {
                solve(lx, ly, rx, s2.second);
                solve(lx, s2.second, rx, ry);
            } else {
                solve(lx, ly, s2.first, ry);
                solve(s2.first, ly, rx, ry);
            }
        }
    };

    solve(0, 0, w, h);
    rep(y, h) {
        rep(x, w) { cout << cut[y][x] << " "; }
        cout << endl;
    }
    return 0;
}