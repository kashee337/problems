#include <algorithm>
#include <cmath>
#include <deque>
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
    for (T i = 2; i * i < n; i++) {
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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> b(n, 0);
    int m = 0;
    rrep(num, n) {
        int sum = 0;
        for (int i = 2 * (num + 1); i <= n; i += (num + 1)) { sum += b[i - 1]; }
        if (sum % 2 != a[num]) {
            b[num] = 1;
            m++;
        }
    }
    // sort(b.begin(), b.end());
    cout << m << endl;
    rep(i, n) {
        if (b[i]) cout << i + 1 << endl;
    }
    return 0;
}