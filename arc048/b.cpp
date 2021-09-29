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
    vector<pair<ll, ll>> rh(n);
    vector<pair<ll, ll>> in_rh(n);
    map<pair<ll, ll>, ll> memo;
    rep(i, n) {
        cin >> rh[i].first >> rh[i].second;
        rh[i].second--;
        in_rh[i] = {rh[i].first, rh[i].second};
        memo[rh[i]]++;
    }
    sort(rh.begin(), rh.end());
    map<pair<ll, ll>, vector<ll>> res;
    rep(i, n) {
        ll r = rh[i].first;
        ll h = rh[i].second;

        ll win_idx = lower_bound(rh.begin(), rh.end(), make_pair(r, 0LL)) - rh.begin();
        ll lose_idx = upper_bound(rh.begin(), rh.end(), make_pair(r, 3LL)) - rh.begin();
        ll win_h = (h + 1) % 3, lose_h = (h + 2) % 3;

        // win
        vector<ll> tmp(3, 0);
        tmp[0] += win_idx;
        tmp[0] += memo[{r, win_h}];
        // lose
        tmp[1] += n - lose_idx;
        tmp[1] += memo[{r, lose_h}];

        // draw
        tmp[2] += memo[{r, h}] - 1;

        res[{r, h}] = tmp;
    }
    rep(i, n) {
        auto tmp = res[in_rh[i]];
        cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;
    }

    return 0;
}