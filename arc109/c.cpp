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
ll n, k;
string s;

char judge(char c1, char c2) {
    if (c1 == c2 || (c1 == 'R' && c2 == 'S') || (c1 == 'S' && c2 == 'P') || (c1 == 'P' && c2 == 'R')) {
        return c1;
    } else {
        return c2;
    }
}
char winners_arts(ll l, ll r) {
    if (r - l == 1) {
        char c1 = s[(l % n)];
        char c2 = s[(r % n)];
        return judge(c1, c2);
    } else if (r == l) {
        return s[(l % n)];
    }
    ll m = (l + r) / 2;
    char c1 = winners_arts(l, m - 1);
    char c2 = winners_arts(m, r);
    return judge(c1, c2);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k >> s;
    cout << winners_arts(0, k) << endl;

    return 0;
}