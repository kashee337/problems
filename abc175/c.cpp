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
bool check(ll n, ll k) { return (n % 2 == 0 && k % 2 != 0) || (n % 2 != 0 && k % 2 == 0); }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    ll n = floor(x / d);
    ll dist;
    if (n >= k) {
        dist = abs(x - k * d);
    } else {
        if (check(n, k)) {
            dist = abs(x - (n + 1) * d);
        } else {
            dist = abs(x - n * d);
        }
    }
    cout << dist << endl;
    return 0;
}