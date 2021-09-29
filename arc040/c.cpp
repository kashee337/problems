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
    ll n;
    cin >> n;

    vector<string> s(n);
    rep(i, n) cin >> s[i];
    ll res = 0;
    rep(r, n) {
        rrep(c, n) {
            if (s[r][c] == 'o') continue;
            rreps(x, 0, c) { s[r][x] = 'o'; }
            if (r + 1 < n) {
                reps(x, n, c) { s[r + 1][x] = 'o'; }
            }
            res++;
            break;
        }
    }
    cout << res << endl;
    return 0;
}