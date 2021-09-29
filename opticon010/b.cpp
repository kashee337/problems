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

vector<long long> get_prime(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n, -1);
    a[0] = 1;
    //素数なら1以上でなんでも良い
    //それ以外の場合、約数に存在しない最小の数値にする
    get_prime(4);
    reps(i, n, 1) {
        ll v = i + 1;
        vector<ll> p = get_prime(v);
        if (p.size() == 2)
            a[i] = 2;
        else {
            map<ll, ll> memo;
            ll l = INF, r = -1;
            for (auto d : p) {
                if (d - 1 != i) {
                    memo[a[d - 1]]++;
                    l = min(l, a[d - 1]);
                    r = max(r, a[d - 1]);
                }
            }
            if (memo.size() == r - l + 1) {
                if (l >= 3)
                    a[i] = 2;
                else
                    a[i] = r + 1;
            } else {
                reps(j, r, l) {
                    if (!memo.count(j)) a[i] = j;
                }
            }
        }
    }
    for (auto v : a) cout << v << endl;
    // rep(i, n) { cout << i + 1 << ":" << a[i] << endl; }
    return 0;
}