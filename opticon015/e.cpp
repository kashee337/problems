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
    vector<ll> a(n + 1);
    rep(i, n + 1) cin >> a[i];
    vector<ll> l(n + 1), r(n + 1);
    l[n] = a[n];
    r[n] = a[n];

    rrep(i, n) {
        l[i] = a[i] + (l[i + 1] + 1) / 2;
        r[i] = a[i] + r[i + 1];
    }
    ll res;
    if (l[0] > 1) {
        res = -1;
    } else {
        res = 0;
        ll crr = 1;
        rep(i, n + 1) {
            res += crr;
            crr -= a[i];
            crr = min(crr * 2, r[i + 1]);
        }

        cout << res << endl;
        return 0;
    }