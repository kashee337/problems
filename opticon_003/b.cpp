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
    ll h, w;
    cin >> h >> w;
    ll res = 0;
    if (w == 1 || h == 1) {
        res = 1;
    } else {
        if (w % 2 == 0) {
            if (h % 2 == 0) {
                res = w * h / 2;
            } else {
                res = w / 2 * h;
            }
        } else {
            if (h % 2 == 0) {
                res = ceil(w / 2.0) * (h / 2.0) + (w / 2) * (h / 2);
            } else {
                res = ceil(w / 2.0) * ceil(h / 2.0) + (w / 2) * (h / 2);
            }
        }
    }
    cout << res << endl;
    return 0;
}