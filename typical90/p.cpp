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
    ll N;
    cin >> N;
    ll a, b, c;
    cin >> a >> b >> c;
    ll res = INF;
    rep(i, 10000) {
        if (a * i <= N) {
            rep(j, 10000) {
                if (a * i + b * j <= N) {
                    ll ck = N - (a * i + b * j);
                    if (ck % c == 0) {
                        ll k = ck / c;
                        res = min(res, (ll)(i + j + k));
                    }
                } else {
                    break;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}