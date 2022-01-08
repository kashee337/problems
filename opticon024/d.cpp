#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
    ll h, w, m;
    cin >> h >> w >> m;
    vector<pair<ll, ll>> bh(h), bw(w);
    rep(i, h) bh[i] = {0, i};
    rep(i, w) bw[i] = {0, i};
    ll hi, wi;
    map<pair<ll, ll>, ll> memo;
    rep(i, m) {
        cin >> hi >> wi;
        hi--, wi--;
        memo[{hi, wi}]++;
        bh[hi].first++, bw[wi].first++;
    }
    sort(bh.begin(), bh.end(), greater<pair<ll, ll>>());
    sort(bw.begin(), bw.end(), greater<pair<ll, ll>>());
    ll max_h = bh[0].first, max_w = bw[0].first;
    vector<ll> bh_idx, bw_idx;
    rep(i, h) {
        if (bh[i].first == max_h)
            bh_idx.pb(bh[i].second);
        else
            break;
    }
    rep(i, w) {
        if (bw[i].first == max_w)
            bw_idx.pb(bw[i].second);
        else
            break;
    }
    ll ans = max_h + max_w - 1;
    for (int idx_h : bh_idx) {
        for (int idx_w : bw_idx) {
            if (memo[{idx_h, idx_w}] == 0) {
                cout << ans + 1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}