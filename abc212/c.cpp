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
    vector<ll> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    ll res = INF;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    rep(i, n) {
        ll idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if (idx < m) res = min(res, abs(a[i] - b[idx]));
        if (idx > 0) res = min(res, abs(a[i] - b[idx - 1]));
    }
    cout << res << endl;
    return 0;
}