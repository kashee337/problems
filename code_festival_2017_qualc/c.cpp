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
    string s;
    cin >> s;

    int n = s.size();
    string t = "";
    for (auto c : s) {
        if (c == 'x') continue;
        t += c;
    }
    string reverse_t = t;
    reverse(t.begin(), t.end());
    if (t == reverse_t) {
        int l_cur = 0, r_cur = n - 1;
        int res = 0;
        while (l_cur < r_cur) {
            char lc = s[l_cur];
            char rc = s[r_cur];
            if (lc == rc) {
                l_cur++;
                r_cur--;

            } else if (lc == 'x') {
                l_cur++;
                res++;
            } else {
                r_cur--;
                res++;
            }
        }
        cout << res << endl;

    } else {
        cout << -1 << endl;
    }
    return 0;
}