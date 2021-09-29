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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    string res = "pairwise coprime";
    ll v = 0;
    rep(i, n) { v = gcd(v, a[i]); }
    if (v > 1) res = "not coprime";

    if (res == "pairwise coprime") {
        eratosthenes();
        map<ll, ll> prime;
        for (auto v : a) {
            set<ll> tmp_prime;
            while (v > 1) {
                tmp_prime.insert(sieve[v]);
                v /= sieve[v];
            }
            for (auto k : tmp_prime) {
                if (prime.count(k) > 0) { res = "setwise coprime"; }
                prime[k]++;
            }
        }
    }

    cout << res << endl;
    return 0;
}