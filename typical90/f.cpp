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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string res = "";
    ll cur = 0;
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> q;
    rep(i, n - k + 1) { q.push({s[i], i}); }
    res = q.top().first;
    cur = q.top().second + 1;
    q.pop();

    while (res.size() < k) {
        int idx = n - k + res.size();
        q.push({s[idx], idx});
        while (q.top().second < cur) { q.pop(); }
        res += q.top().first;
        cur = q.top().second + 1;
        q.pop();
    }

    cout << res << endl;
    return 0;
}