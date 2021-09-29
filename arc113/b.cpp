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
    ll a, b, c;
    cin >> a >> b >> c;
    ll A[5] = {1, 4, 4, 2, 1};
    int a_idx = (a - 1) % 5;
    set<ll> s;
    ll val = 1;
    while (1) {
        val *= b;
        if (s.count(val % A[a_idx])) break;
        s.insert(val % A[a_idx]);
    }
    int res;
    ll res_val;
    if (s.count(0)) {
        // 0があればcがループ以上の場合は0番目のものになる
        if (c >= s.size()) { c = s.size(); }
    } else {
        c = c % s.size();
    }
    ll BC = 1;
    rep(i, c) { BC *= b; }
    BC = ((BC - 1) % A[a_idx]) + 1;
    res_val = 1;
    rep(i, BC) { res_val *= a % 10; }
    string str = to_string(res_val);
    res = str[str.size() - 1] - '0';
    cout << res << endl;
    return 0;
}