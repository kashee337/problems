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
    string s;
    ll res = 0;
    int XA = 0, BX = 0, BA = 0;
    rep(i, n) {
        cin >> s;
        int m = s.size();
        rep(j, m - 1) {
            if (s[j] == 'A' && s[j + 1] == 'B') { res++; }
        }
        if (s[0] == 'B' && s[m - 1] == 'A')
            BA++;
        else if (s[m - 1] == 'A')
            XA++;
        else if (s[0] == 'B')
            BX++;
    }
    res += max(0, BA - 1);
    if (BA > 0) {
        if (XA > 0) {
            res++;
            XA--;
        }
        if (BX > 0) {
            res++;
            BX--;
        }
    }
    res += min(XA, BX);
    cout << res << endl;
    return 0;
}