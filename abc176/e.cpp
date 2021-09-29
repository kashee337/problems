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
    int H, W, m;
    cin >> H >> W >> m;
    map<int, int> h_cnt, w_cnt;
    set<pair<int, int>> hw;
    vector<int> h_idx, w_idx;
    int h_max = -1, w_max = -1;
    rep(i, m) {
        int h, w;
        cin >> h >> w;
        h--, w--;

        h_cnt[h]++;
        w_cnt[w]++;
        if (h_max < h_cnt[h]) { h_max = h_cnt[h]; }
        if (w_max < w_cnt[w]) { w_max = w_cnt[w]; }
        hw.insert({h, w});
    }

    for (auto h_c : h_cnt) {
        if (h_max == h_c.second) { h_idx.pb(h_c.first); }
    }
    for (auto w_c : w_cnt) {
        if (w_max == w_c.second) { w_idx.pb(w_c.first); }
    }

    ll res = h_max + w_max - 1;
    for (auto h : h_idx) {
        for (auto w : w_idx) {
            if (hw.find({h, w}) == hw.end()) {
                res++;
                cout << res << endl;
                return 0;
            }
        }
    }

    cout << res << endl;
    return 0;
}