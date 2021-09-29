#include <algorithm>
#include <cmath>
#include <deque>
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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    priority_queue<ll> q;
    rep(i, n) {
        cin >> a[i];
        q.push(a[i]);
    }
    rep(i, m) {
        ll x = q.top();
        q.pop();
        q.push(x / 2);
    }
    ll ans = 0;
    while (!q.empty()) {
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}