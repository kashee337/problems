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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    map<ll, ll> memo;
    ll cnt = 0;
    ll crr = 0;
    memo[0] = 0;
    while (1) {
        crr = a[crr] - 1;
        cnt++;
        if (memo.count(crr)) { break; }
        memo[crr] = cnt;
        if (cnt == k) break;
    }
    if (cnt < k) {
        ll loop = (cnt - memo[crr]);
        ll d = memo[crr];
        rep(i, (k - d) % loop) { crr = a[crr] - 1LL; }
    }
    cout << crr + 1LL << endl;
    return 0;
}