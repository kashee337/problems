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
    vector<bool> used(1e5 + 1LL, false);
    rep(i, n) {
        ll a;
        cin >> a;
        auto p = get_prime(a);
        for (auto d : p) {
            ll v = d.first;
            if (used[v]) continue;
            ll crr = v;
            while (crr <= m) {
                used[crr] = true;
                crr += v;
            }
        }
    }
    set<ll> res;
    reps(i, m + 1, 1) {
        if (used[i]) continue;
        res.insert(i);
    }
    cout << res.size() << endl;
    for (auto v : res) cout << v << endl;
    return 0;
}