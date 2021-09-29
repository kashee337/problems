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

bool check(ll l, ll r, ll a) {
    if (ceil(l / a) == ceil(r / a) && l % a != 0)
        return false;
    else
        return true;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll k;
    cin >> k;
    vector<ll> a(k);
    rep(i, k) cin >> a[i];
    ll l = 2, r = 2;
    for (int i = k - 1; i >= 0; i--) {
        if (!check(l, r, a[i])) {
            cout << -1 << endl;
            return 0;
        } else {
            l = ceil(l / (double)a[i]) * a[i];
            r = floor(r / (double)a[i]) * a[i] + a[i] - 1;
        }
    }
    cout << l << " " << r << endl;
    return 0;
}