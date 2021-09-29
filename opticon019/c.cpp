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
    ll n, m;
    cin >> n >> m;
    reps(a, n + 1, 0) {
        ll _m = m - 2 * a;
        ll _n = n - a;
        ll c = _m - 3 * _n;
        ll b = _n - c;
        if (b < 0 || c < 0) continue;
        cout << a << " " << b << " " << c << endl;
        return 0;
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}