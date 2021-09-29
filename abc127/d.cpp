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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    map<ll, ll> cnts;
    vector<ll> k;
    rep(i, n) {
        cin >> a[i];
        if (cnts[a[i]] == 0) k.pb(a[i]);
        cnts[a[i]]++;
    }

    rep(i, m) {
        ll b, c;
        cin >> b >> c;
        if (cnts[c] == 0) k.pb(c);
        cnts[c] += b;
    }

    sort(k.begin(), k.end(), greater<ll>());
    ll num = 0;
    ll res = 0;
    for (auto i : k) {
        if (cnts[i] > 0) {
            if (num + cnts[i] <= n) {
                num += cnts[i];
                res += i * cnts[i];
            } else {
                res += i * (n - num);
                num = n;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}