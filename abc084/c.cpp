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
    vector<ll> c(n - 1), s(n - 1), f(n - 1);
    rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];
    vector<ll> res(n, 0);
    rep(i, n - 1) {
        ll t = 0;
        reps(j, n - 1, i) {
            if (t <= s[j]) {
                t = s[j] + c[j];
            } else {
                ll wait_t = ((t - s[j]) % f[j]);
                if (wait_t != 0) wait_t = f[j] - wait_t;
                t += c[j] + wait_t;
            }
        }
        res[i] = t;
    }
    for (auto t : res) cout << t << endl;
    return 0;
}