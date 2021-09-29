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
    ll a, b, c;
    cin >> a >> b >> c;
    string res;
    if ((c % 2 == 0) || (a < 0 && b < 0) || (a > 0 && b > 0)) {
        if (abs(a) > abs(b))
            res = ">";
        else if (abs(a) < abs(b))
            res = "<";
        else
            res = "=";
    } else {
        if (a < 0 && b > 0) {
            res = "<";
        } else if (a > 0 && b < 0) {
            res = ">";
        } else if (a == 0 || b == 0) {
            if (a < b)
                res = "<";
            else if (a > b)
                res = ">";
            else
                res = "=";
        }
    }
    cout << res << endl;
    return 0;
}