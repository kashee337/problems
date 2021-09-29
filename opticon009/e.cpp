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
    ll n, c;
    cin >> n >> c;
    vector<pair<pair<ll, ll>, ll>> stc(n);
    rep(i, n) { cin >> st[i].first.first >> st[i].first.second >> st[i].second; }
    sort(st.begin(), st.end());
    ll crr = 0;
    ll res = 1;
    stack<int> recorder;
    priority_queue<pair<int, int>> q;
    recorder.push(0);
    rep(i, 1e5 + 1) {
        if (!recorder.empty()) {}

        res = crr;
    }
    cout << res << endl;
    return 0;
}