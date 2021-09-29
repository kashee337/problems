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

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ab(n);
    rep(i, n) { cin >> ab[i].first >> ab[i].second; }
    sort(ab.begin(), ab.end());

    priority_queue<int> q;
    ll crr = 0;
    ll res = 0;
    reps(i, m + 1, 1) {
        while (crr < n && ab[crr].first <= i) {
            q.push(ab[crr].second);
            crr++;
        }
        if (!q.empty()) {
            res += q.top();
            q.pop();
        }
    }
    cout << res << endl;
    return 0;
}
// 5 2
// 2 3
// 2 8
// 2 1
// 2 10
// 1 2