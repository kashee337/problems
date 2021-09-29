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
    vector<ll> a(n);
    vector<pair<ll, ll>> ab(n);
    rep(i, n) {
        cin >> a[i];
        ll a_add_b = a[i] + (i + 1);
        ll a_sub_b = (i + 1) - a[i];
        ab[i] = {a_sub_b, a_add_b};
    }
    sort(ab.begin(), ab.end());
    ll res = 0;
    rep(i, n) {
        ll a_add_b = ab[i].second;
        auto itr1 = lower_bound(ab.begin(), ab.end(), pair<ll, ll>(a_add_b, -INF));
        int idx1 = distance(ab.begin(), itr1);
        auto itr2 = upper_bound(ab.begin(), ab.end(), pair<ll, ll>(a_add_b, INF));
        int idx2 = distance(ab.begin(), itr2);
        res += idx2 - idx1;
    }

    cout << res << endl;
    return 0;
}