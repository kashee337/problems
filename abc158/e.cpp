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
    ll n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    ll res = 0;
    if (p == 2) {
        rep(i, n) {
            ll x = s[i] - '0';
            if (x % 2 == 0) res += (i + 1);
        }
    } else if (p == 5) {
        rep(i, n) {
            ll x = s[i] - '0';
            if (x % 5 == 0) res += (i + 1);
        }
    } else {
        map<ll, ll> cnt;
        ll a = 0;
        cnt[a]++;
        ll ten = 1;
        rrep(i, n) {
            a = (a + (s[i] - '0') * ten) % p;
            ten = ten * 10 % p;
            cnt[a]++;
        }
        for (auto k : cnt) {
            ll num = k.second;
            res += num * (num - 1) / 2;
        }
    }
    cout << res << endl;
    return 0;
}