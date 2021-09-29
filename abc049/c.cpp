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
    string s;
    cin >> s;

    stack<string> st;
    st.push(s);
    bool ok = false;
    string t_list[4] = {"dreamer", "dream", "eraser", "erase"};

    while (!st.empty()) {
        string crr_s = st.top();
        st.pop();
        if (crr_s == "") {
            ok = true;
            break;
        }
        for (string t : t_list) {
            int t_len = t.size();
            int s_len = crr_s.size();
            if (s_len < t_len) continue;
            string tmp_s = crr_s.substr(0, t_len);
            if (t == tmp_s) { st.push(crr_s.substr(t_len, s_len - t_len)); }
        }
    }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}