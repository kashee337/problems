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
    ll n, k;
    cin >> n >> k;
    vector<ll> c(n);
    rep(i, n) cin >> c[i];
    map<ll, ll> memo;
    rep(i, k) { memo[c[i]]++; }
    ll res = memo.size();
    reps(i, n, k) {
        ll l = c[i - k], r = c[i];
        memo[l]--;
        if (memo[l] == 0) memo.erase(l);
        memo[r]++;
        res = max(res, (ll)memo.size());
    }
    cout << res << endl;
    return 0;
}