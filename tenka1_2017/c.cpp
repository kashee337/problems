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
    ll N;
    cin >> N;
    reps(x, 3501, 1) {
        reps(y, 3501, 1) {
            ll v1 = N * x * y;
            ll v2 = 4 * x * y - N * (x + y);
            if (v2 > 0 && v1 % v2 == 0 && v1 / v2 <= 3500) {
                ll z = v1 / v2;
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
        }
    }
    return 0;
}