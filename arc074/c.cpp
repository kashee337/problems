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
    ll res = INF;
    rep(i, 2) {
        reps(b1, w / 2 + 1LL, 1) {
            ll s1 = b1 * h;
            if ((w - b1) % 2 == 0 || h % 2 == 0) {
                ll s2 = (h * w - h * b1) / 2;
                res = min(res, abs(s1 - s2));
            } else {
                ll b2 = (w - b1) / 2;
                ll b3 = w - b1 - b2;
                ll s2 = b2 * h;
                ll s3 = b3 * h;
                ll sh = max(max(s1, s2), s3) - min(min(s1, s2), s3);

                res = min(res, sh);

                ll b4 = h / 2;
                ll b5 = h - b4;
                ll s4 = b4 * (w - b1);
                ll s5 = b5 * (w - b1);
                ll sw = max(max(s1, s4), s5) - min(min(s1, s4), s5);
                res = min(res, sw);
            }
        }
        swap(h, w);
    }
    cout << res << endl;

    return 0;
}