#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
    ll n, w;
    cin >> n >> w;
    vector<pair<ll, ll>> ab(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        ab[i] = {a, b};
    }
    sort(ab.begin(), ab.end(), greater<pair<ll, ll>>());
    ll ans = 0;
    rep(i, n) {
        ans += ab[i].first * min(w, ab[i].second);
        w -= ab[i].second;
        if (w <= 0) break;
    }
    cout << ans << endl;
    return 0;
}