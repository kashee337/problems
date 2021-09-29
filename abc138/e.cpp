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
    string s, t;
    cin >> s >> t;
    string ss = s + s;
    map<char, int> memo;
    vector<map<char, int>> s_memo(ss.size());
    rrep(i, ss.size()) {
        s_memo[i] = memo;
        memo[ss[i]] = i;
    }
    ll res = 0;
    int t_cur = 0;
    int s_cur = 0;
    while (t_cur < t.size()) {
        char tc = t[t_cur];
        if (!memo.count(tc)) {
            cout << -1 << endl;
            return 0;
        }
        if (tc == s[s_cur]) {
            s_cur++;
            if (t_cur == t.size() - 1) s_cur--;
        } else
            s_cur = s_memo[s_cur][tc];

        if (s_cur >= s.size()) {
            res += s.size();
            s_cur %= s.size();
        }
        t_cur++;
    }

    res += s_cur + 1;
    cout << res << endl;
    return 0;
}