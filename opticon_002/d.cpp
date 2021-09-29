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
    ll n;

    cin >> n;
    vector<double> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll v1 = a[n - 1];
    ll v2;

    double val = INF;
    ll d = ceil(v1 / 2.0);
    rep(i, n - 1) {
        if (val >= abs(d - a[i])) {
            v2 = a[i];
            val = abs(d - a[i]);
        }
    }

    cout << v1 << " " << v2 << endl;

    return 0;
}