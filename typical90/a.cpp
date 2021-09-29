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
ll n, l, k;
bool check(vector<ll>& a, ll val) {
    ll cut = 0;
    ll prev = 0;
    for (auto v : a) {
        if (v - prev >= val) {
            cut++;
            prev = v;
        }

        if (cut == k) {
            if (l - v >= val)
                return true;
            else
                return false;
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> l >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll left = 0, right = l + 1;
    while (left + 1 < right) {
        ll mid = (left + right) / 2;
        if (check(a, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left << endl;
    return 0;
}