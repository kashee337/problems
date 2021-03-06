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
    map<char, vector<int>> memo;
    rep(i, s.size()) { memo[s[i]].pb(i); }
    ll res = 0;
    ll cur = -1;
    for (char c : t) {
        if (memo.count(c)) {
            auto indice = memo[c];
            int idx = upper_bound(indice.begin(), indice.end(), cur) - indice.begin();
            if (idx == indice.size()) {
                res += indice[0] + (s.size() - cur);
                cur = indice[0];
            } else {
                res += indice[idx] - cur;
                cur = indice[idx];
            }
        } else {
            res = -1;
            break;
        }
    }
    cout << res << endl;
    return 0;
}