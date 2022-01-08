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
constexpr long long MAX_N = 10000010;

long long sieve[MAX_N];

void eratosthenes() {
    for (int i = 0; i < MAX_N; i++) sieve[i] = i;
    for (int i = 2; i * i < MAX_N; i++) {
        if (sieve[i] < i) continue;
        for (int j = i * i; j < MAX_N; j += i) {
            if (sieve[j] == j) sieve[j] = i;
        }
    }
}
ll calc_gcd(ll x, ll y) {
    if (y == 0) return x;
    return calc_gcd(y, x % y);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b;
    cin >> a >> b;
    set<ll> prime;
    set<ll> used;
    eratosthenes();
    for (ll v = 1; v * v <= max(a, b); v++) {
        if (a % v == 0 && b % v == 0) {
            if (!used.count(sieve[v])) {
                prime.insert(v);
                used.insert(sieve[v]);
            }
        }
    }
    cout << prime.size() << endl;
    return 0;
}