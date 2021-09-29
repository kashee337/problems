#include <algorithm>
#include <cmath>
#include <deque>
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
constexpr long long MAX = 200010;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, w;
    cin >> n >> w;
    vector<ll> s(n), t(n), p(n);
    vector<ll> sum(MAX, 0);
    rep(i, n) {
        cin >> s[i] >> t[i] >> p[i];
        sum[s[i]] += p[i];
        sum[t[i]] -= p[i];
    }
    rep(i, MAX - 1) { sum[i + 1] += sum[i]; }
    ll max_w = *max_element(sum.begin(), sum.end());
    if (max_w <= w) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}