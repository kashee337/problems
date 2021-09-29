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

    vector<pair<ll, ll>> lr(n);
    if (m < 0 || m == n || (m == (n - 1) && n >= 2)) {
        cout << -1 << endl;
        return 0;
    } else if (m == 0) {
        ll l = 1;
        rep(i, n) { lr[i] = {l++, l++}; }
    } else {
        ll l = 2;
        ll idx = 0;
        rep(i, m + 1) {
            lr[idx] = {l++, l++};
            idx++;
        }
        lr[idx] = {1, l};
        l++;
        idx++;
        rep(i, n - m - 2) {
            lr[idx] = {l++, l++};
            idx++;
        }
    }
    rep(i, n) { cout << lr[i].first << " " << lr[i].second << endl; }
    return 0;
}
