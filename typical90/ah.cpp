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

    map<int, int> d;
    ll v = 0;
    ll res = -1;
    ll l = 0, r = 0;
    while (l < n || r < n) {
        if (v <= k && r < n) {
            if (d[a[r]] == 0) v++;
            d[a[r]]++;
            r++;
        } else if (v > k || r == n) {
            d[a[l]]--;
            if (d[a[l]] == 0) v--;
            l++;
        }
        if (v <= k) {
            res = max(res, r - l);
            // cout << res << " " << l << " " << r << endl;
        }
    }
    cout << res << endl;
    return 0;
}