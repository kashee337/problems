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
int h, w;
ll dfs(int x, int y, int a, vector<vector<bool>> used) {
    if (y == h) return a == 0;

    if (x == w) return dfs(0, y + 1, a, used);

    if (used[y][x]) return dfs(x + 1, y, a, used);

    ll res = 0;
    if (x + 1 < w && !used[y][x + 1]) {
        used[y][x + 1] = true;
        res += dfs(x + 1, y, a - 1, used);
        used[y][x + 1] = false;
    }

    if (y + 1 < h && !used[y + 1][x]) {
        used[y + 1][x] = true;
        res += dfs(x + 1, y, a - 1, used);
        used[y + 1][x] = false;
    }

    res += dfs(x + 1, y, a, used);
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> h >> w >> a >> b;
    vector<vector<bool>> used(h, vector<bool>(w, false));
    cout << dfs(0, 0, a, used) << endl;
    return 0;
}