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
    ll h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i, h) { rep(j, w) cin >> a[i][j]; }
    vector<ll> sw(h, 0), sh(w, 0);
    rep(i, h) {
        ll val = 0;
        rep(j, w) val += a[i][j];
        sw[i] = val;
    }
    rep(j, w) {
        ll val = 0;
        rep(i, h) val += a[i][j];
        sh[j] = val;
    }
    rep(i, h) {
        rep(j, w) { cout << sw[i] + sh[j] - a[i][j] << " "; }
        cout << endl;
    }

    return 0;
}