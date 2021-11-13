#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
    vector<ll> res(n, 0);
    vector<ll> r, l;
    rep(i, n) {
        char c = s[i];
        if (c == 'R') r.pb(-i);
        if (c == 'L') l.pb(i);
    }
    sort(r.begin(), r.end());
    rep(i, n) {
        char c = s[i];
        if (c == 'R') {
            int idx = *lower_bound(l.begin(), l.end(), i);
            int d = idx - i;
            if (d % 2 == 1) {
                res[idx - 1]++;
            } else {
                res[idx]++;
            }
        } else {
            int idx = -*lower_bound(r.begin(), r.end(), -i);

            int d = i - idx;
            if (d % 2 == 1) {
                res[idx + 1]++;
            } else {
                res[idx]++;
            }
        }
    }
    for (auto v : res) cout << v << endl;
    return 0;
}