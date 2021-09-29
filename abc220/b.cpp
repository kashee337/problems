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
    ll k;
    cin >> k;
    string a, b;
    cin >> a >> b;
    ll res;
    if (k == 10) {
        res = stol(a) * stol(b);
    } else {
        ll av = 0, bv = 0;
        rep(i, a.size()) {
            ll v = a[a.size() - i - 1] - '0';
            av += v * powl(k, i);
        }
        rep(i, b.size()) {
            ll v = b[b.size() - i - 1] - '0';
            bv += v * powl(k, i);
        }
        res = av * bv;
    }
    cout << res << endl;
    return 0;
}