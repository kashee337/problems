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
template <typename T> struct RMQ {
    // const T INF=numeric_limits<T>::max();
    int n;
    vector<T> dat;
    RMQ(int n_) : n(), dat(n_ * 4, 0) {
        int x = 1;
        while (n_ > x) { x *= 2; }
        n = x;
    }

    void update(int i, T y) {
        i += n - 1;
        dat[i] = dat[i] ^ y;
        while (i > 0) {
            i = (i - 1) / 2;
            dat[i] = dat[i * 2 + 1] ^ dat[i * 2 + 2];
        }
    }

    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return 0;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return vl ^ vr;
        }
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    RMQ<ll> rmq(n);
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        rmq.update(i, a[i]);
    }
    rep(i, q) {
        ll t, x, y;
        cin >> t >> x >> y;
        x--;
        if (t == 1) {
            rmq.update(x, y);
        } else {
            cout << rmq.query(x, y) << endl;
        }
    }
    return 0;
}