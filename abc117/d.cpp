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
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;
const int MAX_DIGIT = 50;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> dp(100, vector<ll>(2, -1));
    dp[0][0] = 0;
    rep(d, MAX_DIGIT) {
        ll mask = 1LL << (MAX_DIGIT - d - 1);
        ll num = 0;
        // d桁目が1であるAの個数
        rep(i, n) if (a[i] & mask) num++;
        // i桁目を0にしたコストと1にしたときのコスト
        ll cost0 = mask * num;
        ll cost1 = mask * (n - num);

        // smaller to smaller
        if (dp[d][1] != -1) {
            chmax(dp[d + 1][1], dp[d][1] + max(cost0, cost1));
        }
        // just to smaller
        if (dp[d][0] != -1) {
            if (k & mask) {
                chmax(dp[d + 1][1], dp[d][0] + cost0);
            }
        }
        // just to just
        if (dp[d][0] != -1) {
            if (k & mask)
                chmax(dp[d + 1][0], dp[d][0] + cost1);
            else
                chmax(dp[d + 1][0], dp[d][0] + cost0);
        }
    }
    cout << max(dp[MAX_DIGIT][0], dp[MAX_DIGIT][1]) << endl;
    return 0;
}