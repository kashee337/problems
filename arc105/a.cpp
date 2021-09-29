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
vector<ll> a(4);

bool dfs(ll l, ll r, int i) {
    if (i == 4) { return l == r; }
    return dfs(l + a[i], r, i + 1) || dfs(l, r + a[i], i + 1);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    if (dfs(0, 0, 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}