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
    ll n, h;
    cin >> n >> h;
    vector<pair<ll, ll>> ba(n);
    ll a_max = -1;
    rep(i, n) {
        cin >> ba[i].second >> ba[i].first;
        a_max = max(ba[i].second, a_max);
    }
    sort(ba.begin(), ba.end(), greater<pair<ll, ll>>());
    ll res = 0;
    rep(i, n) {
        if (ba[i].first > a_max) {
            h -= ba[i].first;
            res++;
            if (h <= 0) break;
        } else {
            break;
        }
    }

    if (h > 0) {
        if (h % a_max == 0)
            res += h / a_max;
        else
            res += (h / a_max) + 1;
    }
    cout << res << endl;
    return 0;
}