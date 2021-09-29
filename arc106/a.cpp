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

vector<ll> numpow(ll a, ll max) {
    vector<ll> res;
    res.pb(a);
    ll val = a;
    while (val <= max / a) {
        val *= a;
        res.pb(val);
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a_pow = numpow(3, n), b_pow = numpow(5, n);
    rep(i, a_pow.size()) {
        ll b_val = n - a_pow[i];
        rep(j, b_pow.size()) {
            if (b_val == b_pow[j]) {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}