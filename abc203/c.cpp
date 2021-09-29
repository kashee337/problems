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
    vector<pair<ll, ll>> ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(), ab.end());
    ll crr_a = 0;
    ll idx = 0;
    while (k > 0 && idx < n) {
        ll a = ab[idx].first;
        ll b = ab[idx].second;
        ll dist = a - crr_a;
        if (dist <= k) {
            k -= dist;
            k += b;
            crr_a = a;
            idx++;
        } else {
            crr_a += k;
            k = 0;
        }
    }
    crr_a += k;
    cout << crr_a << endl;
    return 0;
}