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
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> pos, neg;
    rep(i, n) {
        if (a[i] > 0)
            pos.pb(a[i]);
        else
            neg.pb(a[i]);
    }
    ll res;
    vector<pair<ll, ll>> xy;
    if (pos.size() > 0 && neg.size() > 0) {
        rep(i, neg.size() - 1) {
            xy.pb({pos[pos.size() - 1], neg[i]});
            pos[pos.size() - 1] -= neg[i];
        }
        rep(i, pos.size() - 1) {
            xy.pb({neg[neg.size() - 1], pos[i]});
            neg[neg.size() - 1] -= pos[i];
        }
        xy.pb({pos[pos.size() - 1], neg[neg.size() - 1]});
        res = pos[pos.size() - 1] - neg[neg.size() - 1];
    } else {
        if (neg.size() > 0) {
            sort(neg.begin(), neg.end(), greater<ll>());
            pos = neg;
        } else {
            sort(pos.begin(), pos.end());
        }
        reps(i, pos.size() - 1, 1) {
            xy.pb({pos[0], pos[i]});
            pos[0] -= pos[i];
        }
        xy.pb({max(pos[pos.size() - 1], pos[0]), min(pos[pos.size() - 1], pos[0])});
        res = max(pos[pos.size() - 1], pos[0]) - min(pos[pos.size() - 1], pos[0]);
    }
    cout << res << endl;
    for (auto v : xy) cout << v.first << " " << v.second << endl;
    return 0;
}
