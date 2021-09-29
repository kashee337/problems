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
const long double PI = 3.14159265358979323846;

long double calc_volume(ll orig_h, ll comp_h, ll orig_r) {
    long double comp_r = orig_r * (comp_h / (long double)orig_h);
    long double v = PI * comp_r * comp_r * comp_h / 3.0;
    return v;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    vector<pair<pair<ll, ll>, ll>> xrh(n);
    rep(i, n) cin >> xrh[i].first.first >> xrh[i].first.second >> xrh[i].second;
    sort(xrh.begin(), xrh.end());
    ll a, b;
    vector<long double> res;
    rep(i, q) {
        cin >> a >> b;
        long double tmp = 0;
        rep(j, n) {
            ll x = xrh[j].first.first;
            ll r = xrh[j].first.second;
            ll h = xrh[j].second;
            if (x + h <= a || b <= x) continue;
            ll x_min = max(x, a);
            ll x_max = x + h;
            ll rr = max(x + h, b);
            tmp += calc_volume(h, x_max - x_min, r) - calc_volume(h, rr - b, r);
        }
        res.pb(tmp);
    }
    for (auto v : res) { cout << fixed << setprecision(10) << v << endl; }
    return 0;
}