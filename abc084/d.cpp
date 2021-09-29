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
constexpr long long MAX_N = 100010;

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
    ll q;
    cin >> q;
    eratosthenes();
    vector<ll> s(MAX_N + 1, 0);
    reps(i, MAX_N + 1, 3) {
        if (i % 2 == 0) {
            s[i + 1] += s[i];
            continue;
        }
        int crr = 0;
        if (sieve[i] == i && sieve[(i + 1) / 2] == (i + 1) / 2) { crr = 1; }
        s[i + 1] += s[i] + crr;
    }
    int l, r;
    rep(i, q) {
        cin >> l >> r;
        cout << s[r + 1] - s[l] << endl;
    }
    return 0;
}