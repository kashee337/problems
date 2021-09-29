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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    rep(c, k) {
        vector<ll> b(n, 0);
        rep(i, n) {
            ll l = max(0LL, i - a[i]);
            ll r = min(n - 1, i + a[i]);
            b[l]++;
            if (r + 1 < n) b[r + 1]--;
        }
        reps(i, n, 1) { b[i] += b[i - 1]; }
        bool ok = true;
        rep(i, n) {
            a[i] = b[i];
            if (a[i] != n) ok = false;
        }
        if (ok) break;
    }
    rep(i, n) cout << a[i] << " ";
    cout << endl;
    return 0;
}