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
    string x;
    cin >> x;
    map<char, int> d;
    rep(i, 4) { d[x[i]]++; }
    int crr = x[0] - '0';
    bool ok = false;
    reps(i, 4, 1) {
        int v = x[i] - '0';
        if ((crr != 9 && crr + 1 == v) || (crr == 9 && v == 0)) {
            crr = v;
            continue;
        }
        crr = v;
        ok = true;
    }
    if (d.size() != 1 && ok)
        cout << "Strong" << endl;
    else
        cout << "Weak" << endl;
    return 0;
}