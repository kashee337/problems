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
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll r = *max_element(a.begin(), a.end());
    ll gcdd = 0;
    ll ans = 0;
    reps(k, r + 1, 2) {
        int tmp = 0;
        rep(i, n) {
            if (a[i] % k == 0) tmp++;
        }
        if (tmp >= gcdd) {
            gcdd = tmp;
            ans = k;
        }
    }
    cout << ans << endl;
    return 0;
}