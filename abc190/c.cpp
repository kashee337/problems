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
    ll n, m;
    cin >> n >> m;
    vector<pair<int, int>> ab(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ab[i] = {a, b};
    }
    int k;
    cin >> k;
    vector<pair<int, int>> cd(k);
    rep(i, k) {
        int c, d;
        cin >> c >> d;
        c--, d--;
        cd[i] = {c, d};
    }
    ll res = 0;
    ll all = 1 << 16;
    rep(bit, all) {
        vector<ll> dish(n, 0);
        rep(j, k) {
            if (bit & (1 << j)) {
                dish[cd[j].first]++;
            } else {
                dish[cd[j].second]++;
            }
        }
        ll num = 0;
        rep(i, m) {
            int a = ab[i].first;
            int b = ab[i].second;
            if (dish[a] > 0 && dish[b] > 0) num++;
        }
        res = max(res, num);
    }
    cout << res << endl;
    return 0;
}