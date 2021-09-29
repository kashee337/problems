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
    vector<pair<ll, ll>> xy(n);
    rep(i, n) cin >> xy[i].first >> xy[i].second;
    ll max_val = -1;
    rep(i, n) {
        rep(j, n) {
            if (i == j)
                ;
            ll dx = xy[i].first - xy[j].first;
            ll dy = xy[i].second - xy[j].second;

            ll sub = 0;
            rep(k, n) {
                rep(l, n) {
                    if (k == l) continue;
                    if (dx == xy[l].first - xy[k].first && dy == xy[l].second - xy[k].second) sub++;
                }
            }
            if (max_val < sub) max_val = sub;
        }
    }
    cout << n - max_val << endl;
    return 0;
}