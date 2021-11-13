#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
struct SQDC {
    int n, b;
    vector<vector<ll>> a;
    vector<ll> bucket;
    SQDC(vector<vector<ll>>& _a) : a(_a) {
        n = a.size();
        b = sqrt(n);
        bucket.assign(n / b, MAX);
        rep(i, n / b) {
            map<ll, ll> c;
            ll res = -MAX;
            rep(j, b) {
                for (ll k : a[j]) res = max(res, ++c[k]);
            }
            bucket[i] = res;
        }
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll a, b;
    vector<vector<ll>> g(n);
    rep(i, m) {
        cin >> a >> b;
        a--, b--;
        g[b].pb(a);
    }
    rep(i, n) {
        g[i].pb(i);
        sort(g.begin(), g.end());
    }

    return 0;
}