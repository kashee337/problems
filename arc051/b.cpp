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
int k;
bool gcd(int _a, int _b, int cnt) {
    if (_b == 0) return cnt == k;
    return gcd(_b, _a % _b, cnt + 1);
}
ll memo[100];
ll fib(ll a) {
    if (memo[a]) return memo[a];
    if (a < 2) return memo[a] = 1;
    return memo[a] = fib(a - 1) + fib(a - 2);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> k;
    fib(k + 1);
    cout << memo[k + 1] << " " << memo[k] << endl;
    return 0;
}