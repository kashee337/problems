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
    ll n, x;
    cin >> n >> x;
    vector<ll> a;
    rep(i, n) {
        ll _a;
        cin >> _a;
        if (_a != x) a.pb(_a);
    }
    ll m = a.size();
    if (m - 1 >= 0) {
        rep(i, m - 1) cout << a[i] << " ";
        cout << a[m - 1] << endl;
    } else {
        cout << " " << endl;
    }
    return 0;
}