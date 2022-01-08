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
    string s;
    cin >> s;
    ll n = s.size();
    ll k;
    cin >> k;
    ll l = 0, r = 0;
    ll res = 0, crr = 0;
    while (r < n) {
        if (s[r] == '.') crr++;
        r++;
        if (crr > k) {
            while (crr > k && l < r) {
                if (s[l] == '.') crr--;
                l++;
            }
        }
        res = max(res, r - l);
    }
    cout << res << endl;
    return 0;
}