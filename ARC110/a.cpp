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
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    eratosthenes();
    ll n;
    cin >> n;

    // reps(n, 31, 2) {
    ll res = 1;
    map<ll, ll> prime;
    reps(i, n + 1, 2) {
        map<ll, ll> tmp_prime;
        ll v = i;
        while (v > 1) {
            tmp_prime[sieve[v]]++;
            v /= sieve[v];
        }
        for (auto p : tmp_prime) {
            if (prime[p.first] < p.second) {
                res *= p.first * (p.second - prime[p.first]);
                prime[p.first] = p.second;
            }
        }
    }

    // reps(i, n + 1, 2) {
    //     if ((res + 1) % i != 1) cout << "No" << i << " " << (res + 1) % i << endl;
    //     // else
    //     //     cout << "ok" << endl;
    // }
    cout << res + 1 << endl;
    // }

    return 0;
}