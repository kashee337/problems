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
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> sum_xor(n, 0), sum_add(n, 0);
    ll res = 0;
    int r = 0;
    ll sum = 0;
    rep(l, n) {
        while (r < n && (sum ^ a[r]) == (sum + a[r])) {
            sum += a[r];
            r++;
        }
        res += r - l;
        if (l == r)
            r++;
        else {
            sum -= a[l];
        }
    }
    cout << res << endl;
    return 0;
}