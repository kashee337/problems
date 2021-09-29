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
    map<char, int> d;
    for (char c : s) d[c]++;
    ll r = 1000 / 8;
    reps(i, r, 1) {
        ll v = 8 * i;
        string vs = to_string(v);
        map<char, int> _d;
        for (char c : vs) _d[c]++;
        int _r = min(3, (int)s.size()) - (int)vs.size();
        rep(j, _r) {
            _d[0];
            _d[0]++;
        }

        bool ok = true;
        for (auto kv : _d) {
            char c = kv.first;
            int num = kv.second;
            if (d[c] < num) ok = false;
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}