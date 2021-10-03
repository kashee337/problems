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
constexpr int MOD = 998244353;

struct BIT {
    vector<ll> dat;
    const ll n;

  public:
    BIT(int _n) : dat(_n + 5, 0), n(_n) {}

    ll sum(int i) {
        i++;
        ll res = 0;
        while (i > 0) {
            res += dat[i];
            res %= MOD;
            i -= i & (-i);
        }
        return res;
    }
    void add(int i, ll val) {
        i++;
        while (i <= n) {
            dat[i] += val;
            dat[i] %= MOD;
            i += i & (-i);
        }
    }
};

ll modPow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    set<ll> _nums;
    rep(i, n) {
        cin >> a[i];
        _nums.insert(a[i]);
    }
    vector<ll> nums(_nums.begin(), _nums.end());
    rep(i, n) {
        int idx = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin();
        a[i] = idx;
    }
    BIT bit(n);
    const ll div = modPow(2, MOD - 2, MOD);
    ll res = 0;
    rep(i, n) {
        res += modPow(2, i, MOD) * bit.sum(a[i]);
        res %= MOD;
        bit.add(a[i], modPow(div, i + 1, MOD));
    }
    cout << res << endl;
    return 0;
}