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
set<ll> invalid;
ll n, m;
vector<ll> res;
void dfs(string s, int depth) {
    if (depth > m) {
        ll v = stol(s);
        if (v >= n) {
            string vs = to_string(v);
            for (char c : vs) {
                int d = c - '0';
                if (invalid.count(d)) return;
            }
            res.pb(v);
        }
        return;
    }

    rep(i, 10) { dfs(s + to_string(i), depth + 1); }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll k;
    cin >> n >> k;
    m = to_string(n).size() + 1;
    rep(i, k) {
        int d;
        cin >> d;
        invalid.insert(d);
    }
    dfs("", 0);
    sort(res.begin(), res.end());
    cout << res[0] << endl;
    return 0;
}