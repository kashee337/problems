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
template <typename T> struct BIT {
  private:
    vector<T> dat;
    const T n;

  public:
    BIT(int _n) : dat(_n + 1, 0), n(_n) {}
    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += dat[i];
            i -= i & (-i);
        }
        return s;
    }
    T sum(int i, int j) {
        T val_i = sum(i - 1);
        T val_j = sum(j);
        return val_j - val_i;
    }
    void add(int i, T x) {
        while (i <= n) {
            dat[i] += x;
            i += i & (-i);
        }
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    BIT<ll> bit(n);
    rep(i, n) { cin >> a[i]; }
    ll num = 0;
    rep(j, n) {
        num += j - bit.sum(a[j] + 1);
        bit.add(a[j] + 1, 1);
    }
    vector<ll> res;
    res.pb(num);
    rep(k, n - 1) {
        ll sub = ((n - 1) - a[k]) - a[k];
        num += sub;
        res.pb(num);
    }
    for (auto v : res) cout << v << endl;
    return 0;
}