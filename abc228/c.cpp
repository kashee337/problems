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
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    ll p1, p2, p3;
    rep(i, n) {
        cin >> p1 >> p2 >> p3;
        p[i] = p1 + p2 + p3;
    }
    vector<ll> order(p.begin(), p.end());
    sort(order.begin(), order.end());

    rep(i, n) {
        int idx = upper_bound(order.begin(), order.end(), p[i] + 300) - order.begin();
        int rank = n - idx + 1;
        if (rank <= k) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}