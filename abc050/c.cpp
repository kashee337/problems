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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll res = 0;
    if (n % 2 != 0) {
        bool ok = true;
        rep(i, (n - 1) / 2) {
            if (a[2 * i + 1] == a[2 * i + 2] && a[2 * i + 1] == 2 * (i + 1)) continue;
            ok = false;
            break;
        }
        if (ok && a[0] == 0) {
            res = 1;
            rep(i, (n - 1) / 2) { res = res * 2 % MOD; }
        }
    } else {
        bool ok = true;
        rep(i, n / 2) {
            if (a[2 * i] == a[2 * i + 1] && a[2 * i] == 2 * i + 1) continue;
            ok = false;
            break;
        }
        if (ok) {
            res = 1;
            rep(i, n / 2) { res = res * 2 % MOD; }
        }
    }
    cout << res << endl;
    return 0;
}