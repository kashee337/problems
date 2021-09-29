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
    string s;
    cin >> s;
    ll q;
    cin >> q;
    ll t, a, b;
    vector<pair<ll, ll>> ab;
    bool rev = false;
    rep(i, q) {
        cin >> t >> a >> b;
        a--, b--;
        if (t == 1) {
            if (rev) {
                if (b < n) {
                    a += n;
                    b += n;
                } else if (a >= n) {
                    a -= n;
                    b -= n;
                } else {
                    a += n;
                    b -= n;
                }
            }
            ab.pb({a, b});
        } else {
            rev = !rev;
        }
    }

    for (auto v : ab) {
        ll a = v.first;
        ll b = v.second;
        char ca = s[a];
        s[a] = s[b];
        s[b] = ca;
    }
    if (rev) { s = s.substr(n, n) + s.substr(0, n); }

    cout << s << endl;
    return 0;
}