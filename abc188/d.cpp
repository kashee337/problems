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
    ll n, C;
    cin >> n >> C;

    vector<pair<ll, ll>> event;

    rep(i, n) {
        ll a, b, c;
        cin >> a >> b >> c;
        event.pb({a, c});
        event.pb({b + 1, -c});
    }
    sort(event.begin(), event.end());

    ll res = 0, t = 0, fee = 0;
    for (auto v : event) {
        if (v.first != t) {
            res += min(C, fee) * (v.first - t);
            t = v.first;
        }
        fee += v.second;
    }

    cout << res << endl;
    return 0;
}