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
    ll k, n, m;
    cin >> k >> n >> m;
    vector<ll> a(k);

    rep(i, k) { cin >> a[i]; }
    vector<ll> b(k);
    vector<pair<ll, ll>> diff;
    ll b_sum = 0;
    rep(i, k) {
        b[i] = a[i] * m / n;
        b_sum += b[i];
        diff.pb({n - (b[i] * n - a[i] * m), i});
    }

    ll b_diff = m - b_sum;
    if (b_diff > 0) {
        sort(diff.begin(), diff.end(), greater<pair<ll, ll>>());
    } else if (b_diff < 0) {
        sort(diff.begin(), diff.end());
    }
    rep(i, abs(b_diff)) {
        int idx = diff[i].second;
        b[idx] += b_diff > 0 ? 1 : -1;
    }
    for (ll v : b) cout << v << endl;
    return 0;
}