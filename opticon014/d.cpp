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
vector<ll> a, b, c;
vector<ll> res;
void dfs() {}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    a.resize(x), b.resize(y), c.resize(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    vector<ll> ab;
    rep(i, x) { rep(j, y) ab.pb(a[i] + b[j]); }
    sort(ab.begin(), ab.end(), greater<ll>());
    vector<ll> res;
    rep(i, min(k, (int)ab.size())) {
        rep(j, min(k, z)) { res.pb(ab[i] + c[j]); }
    }
    sort(res.begin(), res.end(), greater<ll>());
    rep(i, k) cout << res[i] << endl;

    return 0;
}