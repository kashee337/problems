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
    ll q;
    cin >> q;
    ll v = 0;
    priority_queue<ll> pq;
    vector<ll> res;
    rep(i, q) {
        ll p, x;
        cin >> p;
        if (p == 1) {
            cin >> x;
            pq.push(-(x - v));
        } else if (p == 2) {
            cin >> x;
            v += x;
        } else if (p == 3) {
            res.pb(-pq.top() + v);
            pq.pop();
        }
    }
    for (auto r : res) cout << r << endl;
    return 0;
}