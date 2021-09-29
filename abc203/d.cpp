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

    void add(ll x, ll y, ll v) { _mat[y + 1][x + 1] = v; }
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
        ll v = _mat[y2][x2] - _mat[y2][x1] - _mat[y1][x2] + _mat[y1][x1];
        return v;
    }
};

vector<vector<ll>> a;
ll n, k;
bool check(ll v) {
    Zeta2D s(n, n);
    rep(i, n) {
        rep(j, n) {
            ll d = a[i][j] >= v ? 1 : 0;
            s.add(j, i, d);
        }
    }
    s.build();
    ll target = floor(k * k / 2) + 1;
    rep(y, n - k + 1) {
        rep(x, n - k + 1) {
            ll v = s.get_rect(x, y, x + k, y + k);
            if (v < target) return false;
        }
    }
    return true;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    a = vector<vector<ll>>(n, vector<ll>(n));
    rep(i, n) { rep(j, n) cin >> a[i][j]; }
    ll l = 0, r = (ll)1e9 + 1LL;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}