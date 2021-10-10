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
struct MaxLazySegTree {
  private:
    int n;
    vector<ll> node, lazy;

  public:
    MaxLazySegTree(vector<ll>& v) {
        int m = v.size();
        n = 1;
        while (n < m) n *= 2;
        node.resize(2 * n + 1);
        lazy.resize(2 * n + 1, 0);
        for (int i = 0; i < m; i++) node[i + n] = v[i];
        for (int i = n - 1; i > 0; i--) node[i] = max(node[i * 2], node[i * 2 + 1]);
    }

    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            node[k] = lazy[k];

            if (r - l > 1) {
                lazy[2 * k] = lazy[k];
                lazy[2 * k + 1] = lazy[k];
            }
            lazy[k] = 0;
        }
    }
    void update(int a, int b, ll x, int k = 1, int l = 0, int r = -1) {
        if (r < 0) r = n;
        eval(k, l, r);

        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = x;
            eval(k, l, r);
        } else {
            update(a, b, x, 2 * k, l, (l + r) / 2);
            update(a, b, x, 2 * k + 1, (l + r) / 2, r);
            node[k] = max(node[2 * k], node[2 * k + 1]);
        }
    }
    // [a,b)
    ll getmax(int a, int b, int k = 1, int l = 0, int r = -1) {
        if (r < 0) r = n + 1;
        if (b <= l || r <= a) return 0;
        eval(k, l, r);

        if (a <= l && r <= b) {
            return node[k];
        } else {
            ll vl = getmax(a, b, 2 * k, l, (l + r) / 2);
            ll vr = getmax(a, b, 2 * k + 1, (l + r) / 2, r);
            return max(vl, vr);
        }
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll w, n;
    cin >> w >> n;
    vector<ll> v(w + 5LL);
    MaxLazySegTree ls(v);
    vector<ll> res;
    rep(i, n) {
        ll l, r;
        cin >> l >> r;
        ll v = ls.getmax(l, r + 1) + 1;
        res.pb(v);
        ls.update(l, r + 1, v);
    }
    for (auto h : res) cout << h << endl;

    return 0;
}