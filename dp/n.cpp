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
vector<vector<ll>> dp;
vector<ll> s;
vector<vector<bool>> used;

ll dfs(int l, int r) {
    if (used[l][r]) return dp[l][r];
    used[l][r] = true;
    if (l + 1 == r) return dp[l][r] = 0;

    ll cost = INF;
    reps(m, r, l + 1) {
        ll left = dfs(l, m);
        ll right = dfs(m, r);
        cost = min(cost, left + right);
    }

    return dp[l][r] = cost + (s[r] - s[l]);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    dp.assign(n + 1, vector<ll>(n + 1, INF));
    s.assign(n + 1, 0);
    used.assign(n + 1, vector<bool>(n + 1, false));
    rep(i, n) { s[i + 1] = s[i] + a[i]; }
    cout << dfs(0, n) << endl;
    return 0;
}