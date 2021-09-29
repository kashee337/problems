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
    ll t;
    cin >> t;
    rep(i, t) {
        ll n;
        cin >> n;
        vector<vector<ll>> g((ll)1e9 + 1LL);
        set<ll> st;
        rep(j, n) {
            ll l, r;
            cin >> l >> r;
            g[l].pb(r);
            st.insert(l);
        }

        priority_queue<ll> q;
        bool ok = true;
        reps(i, (ll)1e9 + 1LL, 1) {
            ll low = i;
            ll high = (ll)1e9 + 1LL;
            while (low + 1 < high) { ll mid = (low + high) / 2; }
        }
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}