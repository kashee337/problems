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
    vector<pair<ll, ll>> lr(n);
    rep(i, n) {
        ll t, l, r;
        cin >> t >> l >> r;
        l *= 2, r *= 2;
        if (t == 1) {
            lr[i] = {l, r};
        } else if (t == 2) {
            lr[i] = {l, r - 1};
        } else if (t == 3) {
            lr[i] = {l + 1, r};
        } else {
            lr[i] = {l + 1, r - 1};
        }
    }
    ll res = 0;
    rep(i, n) {
        ll a_l = lr[i].first;
        ll a_r = lr[i].second;
        reps(j, n, i + 1) {
            ll b_l = lr[j].first;
            ll b_r = lr[j].second;
            if (a_l > b_r || a_r < b_l) continue;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}