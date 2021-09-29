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
    ll h, w, n;

    cin >> h >> w >> n;
    vector<ll> a(n), b(n);
    set<ll> _r, _c;
    rep(i, n) {
        cin >> a[i] >> b[i];
        _r.insert(a[i]);
        _c.insert(b[i]);
    }
    vector<ll> r(_r.begin(), _r.end());
    vector<ll> c(_c.begin(), _c.end());
    sort(r.begin(), r.end());
    sort(c.begin(), c.end());
    map<ll, ll> a_conv, b_conv;
    rep(i, r.size()) { a_conv[r[i]] = (ll)i + 1LL; }
    rep(i, c.size()) { b_conv[c[i]] = (ll)i + 1LL; }
    rep(i, n) {
        ll _a = a_conv[a[i]];
        ll _b = b_conv[b[i]];
        cout << _a << " " << _b << endl;
    }
    return 0;
}