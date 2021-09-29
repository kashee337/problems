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
constexpr long long MAX_N = 10000010;

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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    // eratosthenes();
    set<ll> memo;
    rep(i, n) {
        cin >> a[i];
        auto p = get_prime(a[i]);
        for (auto v : p) memo.insert(v.first);
    }

    set<ll> res;
    res.insert(1);
    reps(i, m + 1, 2) {
        auto p = get_prime(i);
        bool ok = true;
        for (auto v : p) {
            if (memo.count(v.first)) ok = false;
        }
        if (ok) res.insert(i);
    }
    cout << res.size() << endl;
    for (auto v : res) cout << v << endl;
    return 0;
}