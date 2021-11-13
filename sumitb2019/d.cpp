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
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> idx[10];
    rep(i, n) idx[s[i] - '0'].pb(i);
    ll res = 0;
    rep(v, 1000) {
        bool ok = true;
        string t = to_string(v);
        while (t.size() < 3) t = '0' + t;
        ll l = -1;
        rep(j, 3) {
            ll i = upper_bound(idx[t[j] - '0'].begin(), idx[t[j] - '0'].end(), l) - idx[t[j] - '0'].begin();
            if (i >= idx[t[j] - '0'].size()) {
                ok = false;
                break;
            }
            l = idx[t[j] - '0'][i];
        }
        if (ok) res++;
    }
    cout << res << endl;
    return 0;
}