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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    int offset = 0;
    ll t, x, y;
    vector<ll> res;
    rep(i, q) {
        cin >> t >> x >> y;
        x--, y--;
        x = (x - offset) < 0 ? n + (x - offset) : (x - offset);
        y = (y - offset) < 0 ? n + (y - offset) : (y - offset);

        if (t == 1) {
            swap(a[x], a[y]);
        } else if (t == 2) {
            offset++;
            offset %= n;
        } else {
            res.pb(a[x]);
        }
    }
    for (auto v : res) cout << v << endl;
    return 0;
}