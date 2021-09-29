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
    ll Q;
    cin >> Q;
    queue<ll> q;
    priority_queue<ll> pq;
    vector<ll> res;
    rep(i, Q) {
        ll c, x;
        cin >> c;
        if (c == 1) {
            cin >> x;
            q.push(x);
        } else if (c == 2) {
            if (pq.empty()) {
                res.pb(q.front());
                q.pop();
            } else {
                res.pb(-pq.top());
                pq.pop();
            }
        } else {
            while (!q.empty()) {
                pq.push(-q.front());
                q.pop();
            }
        }
    }
    for (auto v : res) cout << v << endl;
    return 0;
}
