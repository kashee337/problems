#include <algorithm>
#include <cmath>
#include <deque>
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
int n;
void solve(const vector<ll>& a, vector<ll>& res) {
    ll val = 0;
    int k = 1;
    reps(i, n, 2) {
        val += k * a[i];
        k *= -1;
    }
    res[0] = a[0] - a[1] + val;
    reps(i, n, 1) { res[i] = 2 * a[i - 1] - res[i - 1]; }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> res(n, 0);
    solve(a, res);
    rep(i, n) cout << res[i] << endl;
    return 0;
}