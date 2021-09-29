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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<ll> x(n);
    sort(b.begin(), b.end());
    rep(i, n) x[i] = a[0] ^ b[i];
    sort(x.begin(), x.end());

    set<ll> res;
    rep(i, n) {
        vector<ll> c(n);
        rep(j, n) { c[j] = a[j] ^ x[i]; }
        sort(c.begin(), c.end());
        bool ok = true;
        rep(j, n) if (c[j] != b[j]) ok = false;
        if (ok) res.insert(x[i]);
    }
    cout << res.size() << endl;
    for (auto v : res) cout << v << endl;
    return 0;
}
