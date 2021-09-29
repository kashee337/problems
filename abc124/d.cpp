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
    string s;
    cin >> s;
    // ある区間l,rに存在する直立の人の塊の数を数える
    // その数がK以下で最大の区間の長さを答えれば良いはず
    // 具体的にどうやるか
    // 頭と末尾のみ残して座標圧縮すれば良いか
    int cnt_0 = 0, cnt_1 = 0;
    vector<ll> compress;
    rep(i, n) {
        if (s[i] == '0') {
            cnt_0++;
            if (cnt_1 > 0) compress.pb(cnt_1);
            cnt_1 = 0;
        } else {
            cnt_1++;
            if (cnt_0 > 0) compress.pb(-cnt_0);
            cnt_0 = 0;
        }
    }
    if (cnt_1 > 0) compress.pb(cnt_1);
    if (cnt_0 > 0) compress.pb(-cnt_0);
    ll L = compress.size();
    ll res = 0;
    if (L == 1)
        res = abs(compress[0]);
    else {
        vector<ll> dp(L + 1, 0), dp_r(L, 0);
        ll width = 2 * k;
        rep(i, L) { dp[i + 1] = dp[i] + abs(compress[i]); }
        rep(i, L) {
            ll l = i;
            ll r = min(L, l + width);
            if (compress[l] < 0 && l > 0) l--;
            ll val = dp[r] - dp[l];

            res = max(res, val);
        }
    }
    cout << res << endl;
    return 0;
}