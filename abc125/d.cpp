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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll res = 0;
    int neg_num = 0;
    ll min_num = ll(1e9);
    rep(i, n) {
        cin >> a[i];
        res += abs(a[i]);
        if (a[i] < 0) neg_num++;
        min_num = min(min_num, abs(a[i]));
    }
    if (neg_num % 2 == 1) { res -= 2 * min_num; }
    cout << res << endl;
    return 0;
}