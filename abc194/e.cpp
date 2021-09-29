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
map<ll, ll> s;
priority_queue<ll> q;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    rep(i, m) { s[a[i]]++; }
    rep(i, n + 10) {
        if (s[i] > 0) continue;
        q.push(-i);
    }
    ll res = -q.top();

    reps(i, n, m) {
        s[a[i - m]]--;
        s[a[i]]++;
        if (s[a[i - m]] == 0) q.push(-a[i - m]);
        ll val = -q.top();
        if (res > val) res = val;
    }

    cout << res << endl;
    return 0;
}