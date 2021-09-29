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
ll memo[4001];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    sort(h.begin(), h.end(), greater<ll>());
    h.pb(-1);
    ll res = 1;
    ll crr = 0;
    memo[0] = 1;
    reps(i, 4001, 1) { memo[i] = (memo[i - 1] * i) % MOD; }
    rep(i, n) {
        if (h[i + 1] == h[i]) {
            crr++;
        } else {
            res = res * memo[crr + 1] % MOD;
            crr = 0;
        }
    }

    cout << res << endl;
    return 0;
}