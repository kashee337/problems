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
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> w(n + 1, 0), b(n + 1, 0);
    rrep(i, n) {
        if (s[i] == '.') w[i] += 1;
        w[i] += w[i + 1];
    }
    rep(i, n) {
        if (s[i] == '#') b[i + 1] += 1;
        b[i + 1] += b[i];
    }

    ll res = INF;
    rep(i, n + 1) { res = min(res, b[i] + w[i]); }

    cout << res << endl;
    return 0;
}