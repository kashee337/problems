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
    cin >> n;
    vector<ll> s1(n + 1, 0), s2(n + 1, 0);
    rep(i, n) {
        ll c, p;
        cin >> c >> p;
        if (c == 1) {
            s1[i + 1] = s1[i] + p;
            s2[i + 1] = s2[i];
        } else {
            s1[i + 1] = s1[i];
            s2[i + 1] = s2[i] + p;
        }
    }
    ll q;
    cin >> q;
    vector<ll> ls(q), rs(q);
    rep(i, q) { cin >> ls[i] >> rs[i]; }
    rep(i, q) {
        ll l = ls[i], r = rs[i];
        cout << s1[r] - s1[l - 1] << " " << s2[r] - s2[l - 1] << endl;
    }
    return 0;
}