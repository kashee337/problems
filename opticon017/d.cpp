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

int dfs(int v, int crr) {
    if (v == 0) return crr;
    int _v = v;
    int cnt = 0;
    while (_v > 0) {
        if (v & 1) cnt++;
        _v = _v >> 1;
    }
    return dfs(v % cnt, crr + 1);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    string x;
    cin >> n >> x;
    int cnt = 0;
    rep(i, n) if (x[i] == '1') cnt++;
    rep(i, n) {
        int _cnt = cnt;
        if (x[i] == '1') _cnt--;
        _cnt -= 1;
        cout << dfs(v, 1) << endl;
    }
    return 0;
}