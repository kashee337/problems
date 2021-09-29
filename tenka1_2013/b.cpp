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
    ll q, l;
    cin >> q >> l;
    stack<pair<ll, ll>> st;
    ll v = 0;
    rep(i, q) {
        string s;
        cin >> s;
        if (s == "Push") {
            ll n, m;
            cin >> n >> m;
            if (!st.empty() && st.top().first == m) {
                st.top().second += n;
            } else {
                st.push({m, n});
            }
            v += n;
            if (v > l) {
                cout << "FULL" << endl;
                return 0;
            }
        } else if (s == "Pop") {
            ll n;
            cin >> n;
            ll crr_n = n;
            while (crr_n != 0 && !st.empty()) {
                if (st.top().second > crr_n) {
                    st.top().second -= crr_n;
                    crr_n = 0;
                } else if (st.top().second == crr_n) {
                    st.pop();
                    crr_n = 0;
                } else {
                    crr_n = crr_n - st.top().second;
                    st.pop();
                }
            }
            if (v - n < 0) {
                cout << "EMPTY" << endl;
                return 0;
            }
            v = v - n;
        } else if (s == "Top") {
            if (st.empty()) {
                cout << "EMPTY" << endl;
                return 0;
            }
            cout << st.top().first << endl;
        } else {
            cout << v << endl;
        }
    }
    cout << "SAFE" << endl;
    return 0;
}