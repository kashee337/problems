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
ll r1, c1, r2, c2;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> r1 >> c1 >> r2 >> c2;
    int r = r2 - r1, c = c2 - c1;
    int ans = 3;
    if (!r && !c)
        ans = 0;
    else if (r == c || r == -c || abs(r) + abs(c) <= 3)
        ans = 1;
    else if ((r ^ c ^ 1) & 1 || abs(r + c) <= 3 || abs(r - c) <= 3 || abs(r) + abs(c) <= 6)
        ans = 2;

    cout << ans << endl;
    return 0;
}