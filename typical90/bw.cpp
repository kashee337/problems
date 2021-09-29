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

template <typename T> map<T, T> get_prime(T n) {
    map<T, T> prime;
    T num = n;
    for (T i = 2; i * i <= n; i++) {
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
    ll n;
    cin >> n;
    auto prime = get_prime(n);
    ll num = 0;
    for (auto v : prime) { num += v.second; }
    if (num == 1) {
        cout << 0 << endl;
    } else {
        ll res = 0;
        ll c = 0;
        while (num > 1) {
            if (num % 2 == 1) { c = 1; }
            num /= 2;
            if (num % 2 == 1) {
                num += c;
                c = 0;
            }
            res++;
        }
        cout << res << endl;
    }
    return 0;
}