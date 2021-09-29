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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    ll q;
    cin >> q;
    ll b;
    vector<ll> res(q);
    rep(i, q) {
        cin >> b;
        int l = 0, r = n;

        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (a[mid] > b) {
                r = mid;
            } else {
                l = mid;
            }
        }

        if (r < n) {
            ll v1 = abs(a[l] - b), v2 = abs(a[r] - b);
            res[i] = v1 > v2 ? v2 : v1;
        } else {
            res[i] = abs(a[l] - b);
        }
    }
    for (auto v : res) cout << v << endl;
    return 0;
}