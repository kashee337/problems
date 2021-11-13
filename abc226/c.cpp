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
vector<ll> t, k;
vector<vector<ll>> a;
ll res = 0;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    t.resize(n), k.resize(n);
    a.resize(n);
    rep(i, n) {
        cin >> t[i] >> k[i];
        a[i].resize(k[i]);
        rep(j, k[i]) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    stack<ll> st;
    st.push(n - 1);
    vector<bool> use(n, false);
    while (!st.empty()) {
        int crr = st.top();
        st.pop();
        if (use[crr]) continue;
        use[crr] = true;
        for (auto next : a[crr]) { st.push(next); }
        res += t[crr];
    }
    cout << res << endl;
    return 0;
}