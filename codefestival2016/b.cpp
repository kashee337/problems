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
    ll k, t;
    cin >> k >> t;
    vector<ll> a(t);
    rep(i, t) cin >> a[i];
    sort(a.begin(), a.end());
    a[t - 1]--;
    ll res = 0;
    rep(i, k) {
        sort(a.begin(), a.end());
        if (a[t - 1] == 0) break;
        int idx = upper_bound(a.begin(), a.end(), 0) - a.begin();
        if (a[idx] == a[t - 1] && idx != t - 1) break;
        if (idx == t - 1) {
            res++;
            a[t - 1]--;
        } else {
            a[t - 1]--;
            a[idx]--;
        }
    }
    cout << res << endl;
    return 0;
}