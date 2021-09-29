#include <algorithm>
#include <cmath>
#include <deque>
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

    vector<ll> s(n + 1, 0);
    vector<ll> max_h(n + 1, 0);
    ll tmp = 0;
    rep(i, n) {
        s[i + 1] += a[i] + s[i];
        tmp = max(s[i + 1], tmp);
        max_h[i] = tmp;
    }

    ll sum = 0;
    rep(i, n) { sum += (n - i) * a[i]; }
    vector<ll> origin(n + 1, 0);
    rreps(i, 1, n) {
        origin[i] = sum;
        sum -= s[i];
    }

    ll ans = 0;
    rep(i, n + 1) { ans = max(origin[i] + max_h[i], ans); }

    cout << ans << endl;
    return 0;
}