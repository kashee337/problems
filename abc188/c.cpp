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
    ll m = pow(2, n);
    vector<ll> a(m);

    rep(i, m) cin >> a[i];

    queue<pair<ll, ll>> q;
    rep(i, m) q.push({i + 1, a[i]});
    rep(i, n - 1) {
        queue<pair<ll, ll>> tmp;
        while (!q.empty()) {
            auto a1 = q.front();
            q.pop();
            auto a2 = q.front();
            q.pop();
            if (a1.second < a2.second) {
                tmp.push(a2);
            } else {
                tmp.push(a1);
            }
        }
        q = tmp;
    }
    auto a1 = q.front();
    q.pop();
    auto a2 = q.front();
    q.pop();
    ll res = a1.second < a2.second ? a1.first : a2.first;
    cout << res << endl;
    return 0;
}