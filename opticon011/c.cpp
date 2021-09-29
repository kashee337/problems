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
    ll n, k;
    cin >> n >> k;
    vector<ll> px, nx;
    rep(i, n) {
        ll x;
        cin >> x;
        if (x == 0)
            k--;
        else if (x > 0)
            px.pb(x);
        else
            nx.pb(abs(x));
    }

    ll m1 = px.size(), m2 = nx.size();
    sort(nx.begin(), nx.end());
    vector<ll> sp(m1 + 1, 0), sn(m2 + 1, 0);
    rep(i, m1) sp[i + 1] = px[i];
    rep(i, m2) sn[i + 1] = nx[i];

    ll res = INF;
    rep(i, m1 + 1) {
        int j = k - i;
        if (i > k) continue;
        if (j > m2) continue;
        res = min(res, 2 * sp[i] + sn[j]);
    }

    rep(j, m2 + 1) {
        int i = k - j;
        if (j > k) continue;
        if (i > m1) continue;
        res = min(res, sp[i] + 2 * sn[j]);
    }

    cout << res << endl;
    return 0;
}