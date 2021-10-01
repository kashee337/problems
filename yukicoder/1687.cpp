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
    ll n;
    cin >> n;
    vector<ll> p(n);
    rep(i, n) cin >> p[i];

    vector<ll> idx(n);
    ll res = 0;
    ll sum_v = 0;
    rep(i, n) {
        idx[p[i] - 1] = i + 1;
        sum_v += i + 1;
    }
    ll tmp = 0;
    rrep(i, n) {
        ll sub = 2 * idx[i] + tmp;
        res = max(sum_v - sub, res);
        tmp += idx[i];
    }
    cout << res << endl;

    return 0;
}