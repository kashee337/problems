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
int n, k;
deque<ll> dq;
map<pair<pair<int, int>, int>, ll> memo;
ll dfs(int l, int r, int crr_k) {
    if (memo.count({{l, r}, k})) { return memo[{{l, r}, k}]; }
    ll res = 0;
    if (l < r && crr_k < k) {
        res = max(res, dfs(l + 1, r, crr_k + 1));
        res = max(res, dfs(l, r - 1, crr_k + 1));
    }
    if (r - l < n) {
        vector<ll> buf;
        ll tmp = 0;
        rep(i, l) {
            buf.push_back(dq[i]);
            tmp += dq[i];
        }
        rep(i, n - r) {
            buf.push_back(dq[r + i]);
            tmp += dq[r + i];
        }
        sort(buf.begin(), buf.end());
        int m = buf.size();
        rep(i, min(k - crr_k, m)) {
            if (buf[i] >= 0) break;
            tmp -= buf[i];
        }
        res = max(res, tmp);
    }
    return memo[{{l, r}, k}] = res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    dq.resize(n);
    rep(i, n) cin >> dq[i];

    cout << dfs(0, n, 0) << endl;
    return 0;
}