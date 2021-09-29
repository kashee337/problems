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
    ll n, C;
    cin >> n >> C;
    vector<ll> a(n), b(n), c(n);
    rep(i, n) {
        cin >> a[i] >> b[i] >> c[i];
        b[i] += 1;  //いもす法での立ち下がり点
    }

    //あり得る座標群を重複なしで取得
    set<ll> day_set;
    rep(i, n) {
        day_set.insert(a[i]);
        day_set.insert(b[i]);
    }
    //座標群を昇順にsort
    vector<ll> day_list(day_set.begin(), day_set.end());
    sort(day_list.begin(), day_list.end());
    ll L = day_list.size();  //座標圧縮後の座標の長さ

    //実座標->圧縮座標への変換dictを作る
    map<ll, ll> real2comp;
    rep(i, L) { real2comp[day_list[i]] = i; }

    //圧縮後の座標でいもす法をやっていく
    vector<ll> dp(L + 1, 0);
    //メモ
    rep(i, n) {
        dp[real2comp[a[i]]] += c[i];
        dp[real2comp[b[i]]] -= c[i];
    }
    //シミュレート
    rep(i, L) { dp[i + 1] = dp[i + 1] + dp[i]; }

    // 元座標の区間長さを考慮しながら加算していく
    ll res = 0;
    rep(i, L - 1) { res += (day_list[i + 1] - day_list[i]) * min(C, dp[i]); }

    cout << res << endl;

    return 0;
}