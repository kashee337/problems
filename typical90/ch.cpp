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
    int n, q;
    cin >> n >> q;
    vector<ll> x(q), y(q), z(q), w(q);
    rep(i, q) {
        cin >> x[i] >> y[i] >> z[i] >> w[i];
        x[i]--, y[i]--, z[i]--;
    }
    ll N = 1 << n;
    vector<ll> res;
    ll B = 60;
    rep(b, B) {
        ll tmp = 0;
        rep(bit, N) {
            vector<ll> bit_v(n, 0);
            rep(j, n) {
                if (bit >> j & 1) bit_v[j] = 1;
            }
            bool ok = true;
            rep(i, q) {
                ll v = (w[i] >> b) & 1;
                if (v == (bit_v[x[i]] | bit_v[y[i]] | bit_v[z[i]])) continue;
                ok = false;
            }
            if (ok) tmp++;
        }
        res.pb(tmp);
    }
    ll v = 1;
    for (auto r : res) {
        v *= r;
        v %= MOD;
    }
    cout << v << endl;
    return 0;
}