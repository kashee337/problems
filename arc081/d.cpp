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
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> patterns;
    rep(i, n) {
        if (s1[i] == s2[i]) {
            patterns.pb(0);
        } else {
            patterns.pb(1);
            i++;
        }
    }
    ll res = 1;
    rep(i, patterns.size()) {
        ll v;
        if (i == 0) {
            if (patterns[i] == 0)
                v = 3;
            else
                v = 6;
        } else {
            if (patterns[i] == 0) {
                if (patterns[i - 1] == 0)
                    v = 2;
                else
                    v = 1;
            } else {
                if (patterns[i - 1] == 0)
                    v = 2;
                else
                    v = 3;
            }
        }
        res = (res * v) % MOD;
    }
    cout << res << endl;
    return 0;
}