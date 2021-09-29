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
    string val = to_string(n);
    rep(i, k) {
        priority_queue<int> q1, q2;
        for (auto c : val) {
            if (c == '0') {
                q1.push(c - '0');
            } else {
                q1.push(c - '0');
                q2.push(-(c - '0'));
            }
        }
        ll val1 = 0, val2 = 0;

        while (!q1.empty()) {
            val1 += pow(10, q1.size() - 1) * q1.top();
            q1.pop();
        }
        while (!q2.empty()) {
            val2 += pow(10, q2.size() - 1) * (-q2.top());
            q2.pop();
        }
        val = to_string(val1 - val2);
    }
    cout << val << endl;
    return 0;
}