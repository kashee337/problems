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
    ll m = 0;
    rrep(i, n.size()) {
        if (n[i] != '0') break;
        m++;
    }
    string t = "";
    rep(i, n.size() - m) { t = t += n[i]; }
    string _t = t;
    reverse(_t.begin(), _t.end());
    if (t == _t)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}