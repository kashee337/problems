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
    ll tmp;
    map<int, ll> da, db, dc;
    rep(i, n) {
        cin >> tmp;
        da[tmp % 46]++;
    }
    rep(i, n) {
        cin >> tmp;
        db[tmp % 46]++;
    }
    rep(i, n) {
        cin >> tmp;
        dc[tmp % 46]++;
    }

    ll res = 0;
    rep(i, 46) {
        rep(j, 46) {
            rep(k, 46) {
                if ((i + j + k) % 46 != 0) continue;
                res += da[i] * db[j] * dc[k];
            }
        }
    }
    cout << res << endl;
    return 0;
}