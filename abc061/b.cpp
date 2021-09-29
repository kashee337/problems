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
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(), ab.end());
    vector<ll> a(n), b(n);
    rep(i, n) {
        a[i] = ab[i].first;
        b[i] = ab[i].second;
        if (i > 0) b[i] += b[i - 1];
    }
    int idx = lower_bound(b.begin(), b.end(), k) - b.begin();
    cout << a[idx] << endl;

    return 0;
}