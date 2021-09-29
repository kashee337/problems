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

ll n;
vector<ll> a;

int solve(int i, int tmp_val, vector<ll> val_list) {
    if (i == n) {
        for (auto v : val_list) tmp_val ^= v;
        return tmp_val;
    }
    int res1 = solve(i + 1, tmp_val | a[i], val_list);
    val_list.pb(tmp_val);
    int res2 = solve(i + 1, a[i], val_list);
    if (res1 > res2)
        return res2;
    else
        return res1;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    a = vector<ll>(n);
    rep(i, n) cin >> a[i];
    vector<ll> val_list;
    int res = solve(1, a[0], val_list);

    cout << res << endl;
    return 0;
}