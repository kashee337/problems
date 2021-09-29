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
    vector<ll> a(n);
    ll target = 0;
    rep(i, n) {
        cin >> a[i];
        target += a[i];
    }
    if (target % 10) {
        cout << "No" << endl;
    } else {
        target /= 10;
        ll v = 0;
        ll c1 = 0, c2 = 0;
        while (c2 < n) {
            if (v < target) {
                v += a[c1++];
                c1 %= n;
            } else if (v > target) {
                v -= a[c2++];
            } else {
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }
    return 0;
}