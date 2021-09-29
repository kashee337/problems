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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    eratosthenes();
    set<ll> memo;
    rep(i, n) {
        cin >> a[i];
        memo.insert(sieve[a[i]]);
        memo.insert(a[i] / sieve[a[i]]);
    }

    set<ll> res;
    res.insert(1);
    reps(i, m + 1, 2) {
        if (memo.count(sieve[i])) continue;
        res.insert(sieve[i]);
    }
    cout << res.size() << endl;
    for (auto v : res) cout << v << endl;
    return 0;
}