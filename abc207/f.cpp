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
    vector<pair<ll, ll>> ab(n), cd(n);

    rep(i, n) cin >> ab[i].first >> ab[i].second;
    rep(i, n) cin >> cd[i].first >> cd[i].second;
    sort(cd.begin(), cd.end());
    vector<pair<ll, ll>> v(n);
    v[0] = {cd[0].first, cd[0].second};
    reps(i, n, 1) { v[i] = {cd[i].first - cd[0].first, cd[i].second - cd[0].second}; }
    string res = "Yes";
    sort(ab.begin(), ab.end());
    if (n > 1) {
        rep(i, n) {
            if (i > 0) {
                ll d1 = ab[i].first - ab[0].first;
                ll d2 = ab[i].second - ab[0].second;
                if (d1 != v[i].first || d2 != v[i].second) { res = "No"; }
            }
        }

        rep(rot, 3) {
            if (res == "Yes") {
                cout << res << endl;
                return 0;
            }
            res = "Yes";
            rep(i, n) {
                ll a = ab[i].first;
                ll b = ab[i].second;
                ab[i].first = -b;
                ab[i].second = a;
            }
            sort(ab.begin(), ab.end());
            rep(i, n) {
                if (i > 0) {
                    ll d1 = ab[i].first - ab[0].first;
                    ll d2 = ab[i].second - ab[0].second;
                    if (d1 != v[i].first || d2 != v[i].second) { res = "No"; }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}