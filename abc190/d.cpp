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
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, n, s) for (ll i = (s); i < (n); i++)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; i--)
#define rreps(i, n, s) for (ll i = s; i >= n; i--)

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll res = 0;
    n *= 2;
    reps(i, (ll)1e8, 1) {
        ll b = i * (i - 1);
        if (n - b <= 0) break;
        if ((n - b) % (2 * i) == 0) {
            ll a = (n - b) / (2 * i);
            res += 2;
        }
    }
    cout << res << endl;
    return 0;
}