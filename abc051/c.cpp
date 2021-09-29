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

string move(string res, bool is_return, int dx, int dy) {
    if (is_return) {
        rep(y, abs(dy)) {
            if (dy > 0) {
                res += "D";
            } else {
                res += "U";
            }
        }
        rep(x, abs(dx)) {
            if (dx > 0) {
                res += "L";
            } else {
                res += "R";
            }
        }
    } else {
        rep(y, abs(dy)) {
            if (dy > 0) {
                res += "U";
            } else {
                res += "D";
            }
        }
        rep(x, abs(dx)) {
            if (dx > 0) {
                res += "R";
            } else {
                res += "L";
            }
        }
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx, dy = ty - sy;
    string res = "";
    // 1
    res = move(res, false, dx, dy);
    res = move(res, true, dx, dy);
    // 2
    res += "L";
    res = move(res, false, dx + 1, dy + 1);
    res += "D";
    res += "R";
    res = move(res, true, dx + 1, dy + 1);
    res += "U";
    cout << res << endl;
    return 0;
}
