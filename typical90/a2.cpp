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
ll N, L, k;

bool check(vector<ll>& a, ll mid) {
    int cut = 0;
    int prev = 0;
    rep(i, N) {
        if (a[i] - prev >= mid) {
            prev = a[i];
            cut++;
        }
        if (cut == k) { return L - prev < mid; }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> L;
    cin >> k;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    ll l = 0, r = L + 1;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;

        if (check(a, mid))
            r = mid;
        else
            l = mid;
    }
    cout << l << endl;
    return 0;
}