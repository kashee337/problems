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
    ll res = INF;
    set<char> cs;
    int n = s.size();
    rep(i, n) { cs.insert(s[i]); }
    if(cs.size() == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (char c : cs) {
        ll tmp = 0;
        bool ok = true;
        string t = s;
        while (ok) {
            ok = false;
            string td = "";
            int m = t.size();
            rep(i, m - 1) {
                if (t[i] == c || t[i + 1] == c) {
                    td += c;
                } else {
                    td += t[i];
                    ok = true;
                }
            }
            t = td;
            tmp++;
        }
        res = min(res, tmp);
    }
    cout << res << endl;
    return 0;
    }