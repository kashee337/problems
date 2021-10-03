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
    string n;
    cin >> n;
    sort(n.begin(), n.end());
    ll res = 0;
    ll m = n.size();
    do {
        reps(i, m, 1) {
            string s = n.substr(0, i);
            string t = n.substr(i, m - i);
            if (s[0] == '0' || t[0] == '0') continue;
            ll tmp = stol(s) * stol(t);
            res = max(res, tmp);
        }

    } while (next_permutation(n.begin(), n.end()));
    cout << res << endl;
    return 0;
}