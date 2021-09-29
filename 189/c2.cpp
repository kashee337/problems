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

ll search_maxrect(vector<ll>& a) {
    a.push_back(0);
    int n = a.size();
    stack<pair<int, ll>> s;
    ll res = -1;
    rep(i, n) {
        if (s.empty()) {
            s.push({i, a[i]});
        } else {
            int prev_i = s.top().first;
            ll prev_a = s.top().second;
            if (prev_a < a[i]) {
                s.push({i, a[i]});
            } else if (prev_a > a[i]) {
                while (prev_a > a[i]) {
                    prev_i = s.top().first;
                    res = max(res, prev_a * (i - prev_i));
                    s.pop();
                    if (s.empty()) break;
                    prev_a = s.top().second;
                }

                if (!s.empty()) {
                    s.push({prev_i, a[i]});
                } else {
                    s.push({0, a[i]});
                }
            }
        }
    }
    a.pop_back();
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    cout << search_maxrect(a) << endl;
    return 0;
}