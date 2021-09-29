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
constexpr long long INF = (1LL << 62) - 1LL;
constexpr int MOD = 1000000007;

bool check(ll m, string X, ll n) {
    vector<ll> Y;
    while (0 < m) {
        Y.push_back(m % n);
        m /= n;
    }
    reverse(Y.begin(), Y.end());

    if (X.size() < Y.size())
        return true;
    else if (X.size() > Y.size())
        return false;

    // the same size.
    int len = X.size();
    rep(i, len) {
        ll x = X[i] - '0';
        ll y = Y[i];

        if (x == y)
            continue;
        else if (x < y)
            return true;
        else
            return false;
    }

    // X == Y
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string x;
    ll m;
    cin >> x >> m;
    int res = 0;
    if (x.size() == 1) {
        ll X = x[0] - '0';
        if (X <= m) { res = 1; }
    } else {
        int ma = -1;
        for (auto c : x) { ma = max(ma, c - '0'); }

        ll ok = ma, ng = INF;
        while (ok + 1 < ng) {
            ll md = (ok + ng) / 2;
            if (check(m, x, md))
                ok = md;
            else
                ng = md;
        }
        res = ok - ma;
    }
    cout << res << endl;
    return 0;
}