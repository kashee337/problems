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
    ll n;
    cin >> n;
    string s = to_string(n);
    int len = s.size();
    ll res = 0;
    for (int i = 2; i <= len; i += 2) {
        if (i == len) {
            ll v1 = pow(10, i / 2 - 1);
            ll v2 = 0;
            rep(j, i / 2) {
                if (j > 0) v2 *= 10;
                v2 += s[j] - '0';
            }
            string sv = to_string(v2);
            ll v = stol(sv + sv);
            res += v2 - v1 + 1;
            if (v > n) res -= 1;
        } else {
            ll v1 = pow(10, i / 2 - 1);
            ll v2 = 0;
            rep(j, i / 2) {
                if (j > 0) v2 *= 10;
                v2 += 9;
            }
            res += v2 - v1 + 1;
        }
    }
    cout << res << endl;
    return 0;
}