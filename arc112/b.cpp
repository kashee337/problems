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
    ll b, c;
    cin >> b >> c;
    ll res = 0;
    if (b > 0) {
        if (c / 2 >= b) {
            c -= 1;
            b *= -1;
            res += (c / 2) + ((c - 1) / 2) + min((c - 1) / 2, -2 * b) + 1;
        } else {
            res += (c / 2) + ((c - 1) / 2) + 2;
        }
    } else if (b == 0) {
        res += (c / 2) + ((c - 1) / 2) + 1;
    } else {
        res += (c / 2) + ((c - 1) / 2) + min((c - 1) / 2, -2 * b) + 1;
    }
    cout << res << endl;
    return 0;
}