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
    int a;
    map<int, int> color;
    rep(i, n) {
        cin >> a;
        if (a > 3200) a = 3200;
        color[a / 400]++;
    }

    ll res = 0;
    ll all = 0;
    rep(i, 9) {
        if (i < 8) {
            if (color[i]) res++;
        } else {
            all = color[i];
        }
    }
    cout << max(res, (ll)1) << " " << res + all << endl;
    return 0;
}