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

ll calc_cost(map<int, int> num, int c) {
    int all_n = 0;
    int max_n = -1;
    for (auto v : num) {
        all_n += v.second;
        max_n = max_n < v.second ? v.second : max_n;
    }
    return (all_n - max_n) * c;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> odd_map, even_map;
    rep(i, n) {
        if (i % 2 == 0) {
            even_map[a[i]]++;
        } else {
            odd_map[a[i]]++;
        }
    }
    vector<pair<ll, ll>> odd_cost, even_cost;
    int odd_n = n / 2;
    int even_n = n % 2 == 0 ? n / 2 : n / 2 + 1;
    for (auto v : odd_map) { odd_cost.pb({c * (odd_n - v.second), v.first}); }
    for (auto v : even_map) { even_cost.pb({c * (even_n - v.second), v.first}); }
    sort(odd_cost.begin(), odd_cost.end());
    sort(even_cost.begin(), even_cost.end());
    ll res;
    if (odd_cost[0].second == even_cost[0].second) {
        if (odd_cost.size() > 1 && even_cost.size() > 1) {
            res = INF;
            rep(i, 2) {
                int cost = odd_cost[i].first + even_cost[(i + 1) % 2].first;
                res = res > cost ? cost : res;
            }

        } else {
            if (odd_cost.size() == 1 && even_cost.size() == 1) {
                res = c * odd_n;
            } else if (odd_cost.size() == 1) {
                res = even_cost[1].first < even_cost[0].first + c * odd_n ? even_cost[1].first
                                                                          : even_cost[0].first + c * odd_n;
            } else {
                res = odd_cost[1].first < odd_cost[0].first + c * even_n ? odd_cost[1].first
                                                                         : odd_cost[0].first + c * even_n;
            }
        }
    } else {
        res = odd_cost[0].first + even_cost[0].first;
    }

    cout << res << endl;
    return 0;
}