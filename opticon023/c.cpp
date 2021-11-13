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
    vector<string> s;
    int n;
    string _s;
    getline(cin, _s);
    string __s = "";
    for (char c : _s) {
        if (c == ' ') {
            s.pb(__s);
            __s = "";
        } else {
            __s += c;
        }
    }
    s.pb(__s);
    cin >> n;
    vector<string> t(n);
    rep(i, n) cin >> t[i];
    vector<string> res;

    for (auto _s : s) {
        bool ok = false;
        rep(i, n) {
            if (t[i].size() != _s.size()) {
                ok = false;
                continue;
            }
            ok = true;
            string __s = "";
            rep(j, t[i].size()) {
                char c1 = t[i][j];
                char c2 = _s[j];
                __s += "*";
                if (c1 == '*') continue;
                if (c1 != c2) ok = false;
            }
            if (ok) {
                res.pb(__s);
                break;
            }
        }
        if (!ok) { res.pb(_s); }
    }
    rep(i, res.size()) {
        cout << res[i];
        if (i < res.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}