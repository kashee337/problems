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
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    ll dr = r2 - r1, dc = c2 - c1;
    if (dr == 0 && dc == 0) {
        cout << 0 << endl;
    } else if (abs(dr) == abs(dc) || (abs(dr) + abs(dc) <= 3)) {
        cout << 1 << endl;
    } else if (abs(dr) % 2 == abs(dc) % 2) {
        cout << 2 << endl;
    } else {
        ll r3, c3;

        if (dr == 0 || dc == 0) {
            r3 = r1, c3 = c1;
        } else {
            r3 = r1 + dr, c3 = c1 + abs(dr) * (dc / abs(dc));
        }
        ll dr2 = r2 - r3, dc2 = c2 - c3;

        if ((abs(dr2) + abs(dc2) <= 3) || (abs(dr) + abs(dc) <= 6)) {
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        }
    }
    return 0;
}