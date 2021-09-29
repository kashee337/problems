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
    vector<ll> r(n);
    rep(i, n) cin >> r[i];
    vector<ll> _r;
    ll prev = -INF;
    rep(i, n) {
        if (r[i] != prev) _r.pb(r[i]);
        prev = r[i];
    }
    int _n = _r.size();
    vector<ll> edge(_n, false);
    edge[0] = true;
    edge[_n - 1] = true;
    reps(i, _n - 1, 1) {
        if ((_r[i - 1] - _r[i]) * (_r[i + 1] - _r[i]) > 0) edge[i] = true;
    }
    ll res = 0;
    for (auto e : edge) {
        if (e) res++;
    }
    if (res <= 2) res = 0;
    cout << res << endl;
    return 0;
}