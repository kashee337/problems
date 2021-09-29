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
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    vector<vector<ll>> xyz(8, vector<ll>(n));
    int sign[2] = {1, -1};
    rep(i, n) {
        cin >> x[i] >> y[i] >> z[i];
        rep(j, 2) {
            rep(k, 2) { rep(l, 2) xyz[j * 4 + k * 2 + l][i] = sign[j] * x[i] + sign[k] * y[i] + sign[l] * z[i]; }
        }
    }
    ll res = 0;
    rep(j, 8) {
        ll tmp = 0;
        sort(xyz[j].begin(), xyz[j].end(), greater<ll>());
        rep(i, m) { tmp += xyz[j][i]; }
        res = max(res, tmp);
    }
    cout << res << endl;
    return 0;
}