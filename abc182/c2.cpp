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
    int k = n.size();
    ll v = 0;
    map<int, int> d;
    for (char c : n) {
        v += c - '0';
        d[(c - '0') % 3]++;
    }
    v %= 3;
    ll res;
    if (v % 3 == 0) {
        res = 0;
    } else if (v % 3 == 1) {
        if (d[1] >= 1) {
            if (k == 1)
                res = -1;
            else
                res = 1;
        } else {
            if (k <= 2)
                res = -1;
            else
                res = 2;
        }
    } else {
        if (d[2] >= 1) {
            if (k == 1)
                res = -1;
            else
                res = 1;
        } else {
            if (k <= 2)
                res = -1;
            else
                res = 2;
        }
    }
    cout << res << endl;
    return 0;
}