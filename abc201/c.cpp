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
string zero_padding(ll n, ll digit) {
    string s = "";
    string t = to_string(n);
    if (t.size() > digit) { return t; }
    rep(i, digit) {
        s = to_string(n - (n / 10) * 10) + s;
        n /= 10;
    }
    return s;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<int> must, prohibit;
    rep(i, s.size()) {
        if (s[i] == 'o') {
            must.pb(i);
        } else if (s[i] == 'x') {
            prohibit.pb(i);
        }
    }

    ll res = 0;
    rep(i, 10000) {
        string s = zero_padding(i, 4);
        map<int, int> d;
        for (auto c : s) { d[c - '0']++; }
        bool ok = true;
        for (auto c : must) {
            if (d[c] == 0) ok = false;
        }
        for (auto c : prohibit) {
            if (d[c] > 0) ok = false;
        }
        if (ok) { res++; }
    }
    cout << res << endl;
    return 0;
}