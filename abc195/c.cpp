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

ll comma(ll n) {
    ll num = 0;
    while (n > 0) {
        n /= 1000;
        num++;
    }
    return num - 1;
}
ll calc(int num) {
    ll res = 0;
    rep(i, num) {
        if (i > 0) res *= 1000;
        res += 999;
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll res = 0;
    while (n > 0) {
        ll comma_num = comma(n);
        ll nn = calc(comma_num);
        res += comma_num * (n - nn);
        n = nn;
    }
    cout << res << endl;
    return 0;
}