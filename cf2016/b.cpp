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
    vector<ll> s(n + 1, 0);
    rep(i, n) { s[i + 1] = s[i] + i + 1; }
    int idx;
    rep(i, n + 1) {
        if (s[i] >= n) {
            idx = i;
            break;
        }
    }
    vector<ll> res;
    ll crr = 0;
    for (int i = idx; i > 0; i--) {
        ll v = n - crr;
        if (v <= s[i] && v > s[i - 1]) {
            crr += i;
            res.pb(i);
        }
    }
    sort(res.begin(), res.end());
    for (auto v : res) { cout << v << endl; }
    return 0;
}