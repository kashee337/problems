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
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll n = s.size();
    rep(i, n) {
        ll dist = ('z' + 1) - s[i];
        if (dist <= k && s[i] != 'a') {
            s[i] = 'a';
            k -= dist;
        }
    }
    ll w = 'z' - 'a' + 1;
    if (k > 0) {
        ll dist = ('z' + 1) - s[n - 1];
        if (dist <= k) {
            s[n - 1] = 'a' + (k - dist) % w;
        } else {
            s[n - 1] += k;
        }
    }

    cout << s << endl;
    return 0;
}