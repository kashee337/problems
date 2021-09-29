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
vector<vector<ll>> comb;
void gen_combination(ll v, ll n, ll m, vector<ll> buf) {
    if (buf.size() == m) {
        comb.pb(buf);
        return;
    }
    if (v > n) return;
    gen_combination(v + 1, n, m, buf);
    buf.pb(v);
    gen_combination(v + 1, n, m, buf);
    return;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, C;
    cin >> N >> C;
    vector<vector<ll>> d(C, vector<ll>(C));
    rep(i, C) rep(j, C) cin >> d[i][j];
    vector<vector<ll>> c(N, vector<ll>(N));
    rep(i, N) rep(j, N) cin >> c[i][j];
    map<ll, map<ll, ll>> memo;
    rep(i, N) rep(j, N) memo[(i + j + 2) % 3][c[i][j]]++;
    vector<ll> buf;
    gen_combination(1, C, 3, buf);
    ll res = INF;
    for (auto vec : comb) {
        do {
            ll tmp = 0;
            rep(i, 3) {
                for (auto v : memo[i]) { tmp += v.second * d[v.first - 1][vec[i] - 1]; }
            }
            res = min(tmp, res);
        } while (next_permutation(vec.begin(), vec.end()));
    }
    cout << res << endl;
    return 0;
}