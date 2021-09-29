#include <algorithm>
#include <cmath>
#include <deque>
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int res = 0;
    deque<int> q;
    rep(i, n - 1) {
        if (s[i] == s[i + 1])
            res++;
        else if (s[i] != s[i + 1]) {
            if (s[i] == 'L')
                q.emplace_back(1);
            else
                q.emplace_back(-1);
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        if (q.size() == 1) res++;
        int l = q.front();
        q.pop_front();
        while (!q.empty() && l == q.front()) { q.pop_front(); }
        if (q.empty()) break;
        q.pop_front();
        res += 2;
        cnt++;
        if (cnt == k) break;
    }
    cout << res << endl;
    return 0;
}