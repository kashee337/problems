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
    vector<pair<ll, ll>> d(n);

    ll a, b;
    ll all_a = 0;
    rep(i, n) {
        cin >> a >> b;
        all_a += a;
        d[i] = {a + b + a, a};
    }
    sort(d.begin(), d.end(), greater<pair<ll, ll>>());
    ll all_b = 0;
    ll res = 0;
    rep(i, n) {
        auto p = d[i];
        all_a -= p.second;
        all_b += p.first - p.second;
        res++;
        if (all_b > all_a) break;
    }
    cout << res << endl;
    return 0;
}