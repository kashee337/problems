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
ll comb(ll n, ll r) {
    ll res = 1;
    r = min(r, n - r);
    rep(i, r) { res *= (n - i); }
    rep(i, r) { res /= (i + 1); }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, p;

    cin >> n >> p;
    vector<ll> a(n);
    ll odd = 0, even = 0;
    rep(i, n) {
        cin >> a[i];
        if (a[i] % 2 == 1)
            odd++;
        else
            even++;
    }

    ll e = 1;
    rep(i, even) e *= 2;
    ll o = 0;
    ll k = 0;
    if (p == 0) {
        for (int i = 0; i <= odd; i += 2) { o += comb(odd, i); }
    } else {
        for (int i = 1; i <= odd; i += 2) { o += comb(odd, i); }
    }
    cout << o * e << endl;
    return 0;
}
