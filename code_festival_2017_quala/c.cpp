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
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    map<char, int> d;
    rep(i, h) for (char c : a[i]) d[c]++;

    if (h > 1 && w > 1) {
        ll v1 = 0, v2 = 0, v4 = 0;
        if (w % 2 == 1 && h % 2 == 1) { v1++; }
        if (w % 2 == 1) { v2 += h - (h % 2); }
        if (h % 2 == 1) { v2 += w - (w % 2); }
        v2 /= 2;
        v4 = (h * w - (v1 + 2 * v2)) / 4;

        priority_queue<ll> pq;
        for (auto v : d) pq.push(v.second);
        vector<pair<ll, ll>> b{{v4, 4}, {v2, 2}, {v1, 1}};
        for (auto v : b) {
            rep(i, v.first) {
                ll val = pq.top();
                if (val >= v.second) {
                    pq.pop();
                    ll e = val - v.second;
                    if (e > 0) pq.push(e);
                } else {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
        cout << "Yes" << endl;

    } else {
        ll odd = 0;
        for (auto v : d) {
            if (v.second % 2 != 0) odd++;
        }
        int v = max(h, w);

        if (v % 2 == 1) {
            if (odd == 1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        } else {
            if (odd == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}