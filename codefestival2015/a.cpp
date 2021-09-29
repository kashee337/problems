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
    ll n, k, M, R;
    cin >> n >> k >> M >> R;
    vector<ll> s(n - 1);
    rep(i, n - 1) cin >> s[i];
    sort(s.begin(), s.end(), greater<ll>());

    ll S_sum = 0;
    rep(i, k - 1) S_sum += s[i];

    ll l = -1, r = M;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        ll avg_score = (S_sum + mid) / k;
        if (avg_score >= R) {
            r = mid;
        } else {
            l = mid;
        }
    }
    ll avg_score = (S_sum + r) / k;
    if (avg_score >= R) {
        if (k < n && s[k - 1] >= r) {
            cout << 0 << endl;
        } else {
            cout << r << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}