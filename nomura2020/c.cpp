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
    vector<ll> s(n + 1, 0);
    s[n] = a[n];
    rrep(i, n) { s[i] = s[i + 1] + a[i]; }
    if (n == 0) {
        if (a[0] == 1)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    } else {
        ll res = 1;
        ll crr = 1;
        rep(i, n) {
            ll next = (crr - a[i]) * 2;
            if (next <= 0) {
                cout << -1 << endl;
                return 0;
            }
            crr = next > s[i + 1] ? s[i + 1] : next;
            res += crr;
        }
        if (crr == a[n]) {
            cout << res << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}