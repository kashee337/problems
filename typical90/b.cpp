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
bool check(string s) {
    stack<char> st;
    for (auto c : s) {
        if (c == '(') {
            st.push(c);
        } else {
            if (st.empty() || st.top() != '(')
                return false;
            else
                st.pop();
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll m = 1 << n;
    vector<string> res;
    rep(bit, m) {
        string t = "";
        rep(i, n) {
            if (bit >> i & 1) {
                t = t + "(";
            } else {
                t = t + ")";
            }
        }
        if (check(t)) res.pb(t);
    }
    sort(res.begin(), res.end());
    for (auto t : res) cout << t << endl;
    return 0;
}