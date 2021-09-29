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

bool check(int r1, int c1, int r2, int c2) {
    bool b1 = (r1 + c1) == (r2 + c2);
    bool b2 = (r1 - c1) == (r2 - c2);
    bool b3 = abs(r1 - r2) + abs(c1 - c2) <= 3;
    return b1 || b2 || b3;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    ll res = 0;
    if (r1 != r2 || c1 != c2) {
        if (check(r1, c1, r2, c2)) {
            res = 1;
        } else {
            ll dr = abs(r1 - r2);
            ll dc = abs(c1 - c2);
            if (dr % 2 == dc % 2) {
                res = 2;
            } else {
                ll p_c2 = r1 + c1 - r2;
                ll n_c2 = r2 - (r1 - c1);
                bool b = abs(r1 - r2) + abs(c1 - c2) <= 6;
                if (check(r2, c2, r2, p_c2) || check(r2, c2, r2, n_c2) || b) {
                    res = 2;
                } else {
                    res = 3;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}