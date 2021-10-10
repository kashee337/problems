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
constexpr long long MAX_N = 1e7 + 10LL;

map<ll, ll> get_prime(ll n) {
    map<ll, ll> prime;
    ll num = n;
    for (ll i = 2; i * i <= n; i++) {
        while (num % i == 0) {
            prime[i]++;
            num /= i;
        }
    }
    if (num > 1) prime[num]++;

    return prime;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    ll res = 0;
    vector<ll> c(n + 1, 0);
    reps(i, n + 1, 2) {
        if (c[i] != 0) continue;
        int r = 1;
        while (r * i <= n) {
            c[r * i]++;
            r++;
        }
    }
    rep(i, n + 1) if (c[i] >= k) res++;
    cout << res << endl;
    return 0;
}