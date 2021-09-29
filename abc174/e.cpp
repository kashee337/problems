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
ll n, k;
vector<ll> a;
bool solve(double x) {
    ll num = 0;
    rep(i, n) { num += ceil(a[i] / x) - 1; }
    return num <= k;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    a.resize(n);
    rep(i, n) cin >> a[i];
    double l = 0, r = 1000000010;
    rep(i, 100) {
        double mid = (l + r) / 2;
        if (solve(mid))
            r = mid;
        else
            l = mid;
    }
    ll res = ceil(l);
    cout << res << endl;
    return 0;
}