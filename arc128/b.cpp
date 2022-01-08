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
    int t;
    cin >> t;
    rep(i, t) {
        vector<ll> rgb(3);
        cin >> rgb[0] >> rgb[1] >> rgb[2];
        sort(rgb.begin(), rgb.end());
        ll res = INF;
        do {
            if (rgb[1] <= rgb[2] && (rgb[2] - rgb[1]) % 3 == 0) { res = min(res, rgb[2]); }
        } while (next_permutation(rgb.begin(), rgb.end()));
        if (res == INF) res = -1;
        cout << res << endl;
    }
    return 0;
}