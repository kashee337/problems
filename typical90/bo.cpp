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
    int k;
    cin >> n >> k;
    string res;
    rep(j, k) {
        // 十進数に直す
        ll m = n.size();
        ll digit_10 = 0;
        for (ll i = m - 1; i >= 0; i--) { digit_10 += (n[i] - '0') * powl(8, m - 1LL - i); }

        string t = "";
        while (digit_10 > 0) {
            t += to_string(digit_10 % 9);
            digit_10 /= 9;
        }
        reverse(t.begin(), t.end());
        if (t == "") t = "0";
        t = to_string(stol(t));
        rep(i, t.size()) t[i] = t[i] == '8' ? '5' : t[i];
        res = t;
        n = t;
    }
    cout << stol(res) << endl;
    return 0;
}