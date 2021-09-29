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
    vector<ll> z(n), w(n);
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        z[i] = x + y;
        w[i] = x - y;
    }
    sort(z.begin(), z.end());
    sort(w.begin(), w.end());
    ll dist = max(z[n - 1] - z[0], w[n - 1] - w[0]);
    cout << dist << endl;
    return 0;
}