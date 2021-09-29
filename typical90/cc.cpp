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
struct Zeta2D {
    vector<vector<ll>> _mat;
    ll N1, N2;
    Zeta2D(ll _N1, ll _N2) {
        N1 = _N1;
        N2 = _N2;
        _mat.resize(_N1 + 1, vector<ll>(_N2 + 1, 0));
    }
    void init(ll _N1, ll _N2) {
        N1 = _N1;
        N2 = _N2;
        _mat.resize(_N1 + 1, vector<ll>(_N2 + 1, 0));
    }

    void add(ll x, ll y, ll v) { _mat[y][x] += v; }
    void build() {
        rep(i, N1 + 1) {
            rep(j, N2) { _mat[i][j + 1] += _mat[i][j]; }
        }
        rep(i, N1) {
            rep(j, N2 + 1) { _mat[i + 1][j] += _mat[i][j]; }
        }
    }
    ll get(ll x, ll y) { return _mat[y + 1][x + 1]; }

    ll get_rect(ll x1, ll y1, ll x2, ll y2) {
        ll v = _mat[y2][x2] - _mat[y2][x1 - 1] - _mat[y1 - 1][x2] + _mat[y1 - 1][x1 - 1];
        return v;
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    Zeta2D dp(5002, 5002);

    rep(i, n) {
        cin >> a[i] >> b[i];
        dp.add(a[i], b[i], 1);
    }
    dp.build();
    ll res = 0;
    reps(a, 5001 - k, 1) {
        reps(b, 5001 - k, 1) {
            ll tmp = dp.get_rect(a, b, a + k, b + k);
            res = max(res, tmp);
        }
    }
    cout << res << endl;
    return 0;
}