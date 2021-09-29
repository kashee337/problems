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
    int t;
    cin >> t;
    string a = "atcoder";
    vector<int> res;
    rep(i, t) {
        string s;
        cin >> s;
        int r = 10000;
        vector<int> n(a.size(), -1);
        bool ok = true;
        rep(i, min(a.size(), s.size())) {
            if (a[i] != s[i])
                ok = false;
            else
                n[i] = 0;
        }
        if (ok && a.size() < s.size()) {
            r = 0;
        } else {
            rep(i, a.size()) {
                reps(j, s.size(), i) {
                    if (a[i] < s[j]) {
                        r = min(r, j - i);
                        break;
                    }
                }
                if (n[i] == -1) break;
            }
            if (r == 10000) r = -1;
        }
        res.pb(r);
    }
    for (auto r : res) cout << r << endl;
    return 0;
}