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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> ab(n), cd(m);
    rep(i, n) cin >> ab[i].first >> ab[i].second;
    rep(i, m) cin >> cd[i].first >> cd[i].second;
    vector<int> res;
    rep(i, n) {
        ll val = INF;
        int idx;
        rep(j, m) {
            ll dist = abs(ab[i].first - cd[j].first) + abs(ab[i].second - cd[j].second);
            if (val > dist) {
                val = dist;
                idx = j;
            }
        }
        res.pb(idx);
    }
    for (int idx : res) { cout << idx + 1 << endl; }
    return 0;
}