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
    ll n, d, k;
    cin >> n >> d >> k;
    vector<pair<ll, ll>> lr(d);
    vector<pair<pair<ll, ll>, ll>> st(k);
    rep(i, d) cin >> lr[i].first >> lr[i].second;
    rep(i, k) {
        cin >> st[i].first.first >> st[i].first.second;
        st[i].second = st[i].first.first;
    }
    vector<ll> res(k, 0);
    rep(i, d) {
        ll l = lr[i].first;
        ll r = lr[i].second;
        rep(j, k) {
            ll s = st[j].first.first;
            ll t = st[j].first.second;
            if (st[j].second != t) {
                if (l <= st[j].second && st[j].second <= r) {
                    if (s < t) {
                        st[j].second = min(t, r);
                    } else {
                        st[j].second = max(t, l);
                    }
                }
                res[j]++;
            }
        }
    }
    for (auto res_d : res) cout << res_d << endl;

    return 0;
}