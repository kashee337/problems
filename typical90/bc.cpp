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
ll n, p, q, res = 0;
vector<ll> a;
void dfs(ll idx, ll val, ll cnt) {
    if (cnt == 5) {
        if (val % p == q) res++;
        return;
    } else if (n - idx + cnt < 5)
        return;
    dfs(idx + 1, val, cnt);
    val *= a[idx];
    val %= p;
    dfs(idx + 1, val, cnt + 1);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> p >> q;
    a.resize(n);
    rep(i, n) cin >> a[i];
    dfs(0, 1, 0);
    cout << res << endl;
    return 0;
}