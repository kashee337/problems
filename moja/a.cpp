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
    string n;
    cin >> n;
    vector<string> memo;
    rep(i, 10001) {
        ll crr = i;
        memo.pb(to_string(crr * crr * crr));
    }
    for (string s : memo) {
        if (s == n) {
            cout << "cubic" << endl;
            return 0;
        }
    }
    sort(n.begin(), n.end(), greater<char>());
    for (string s : memo) {
        sort(s.begin(), s.end(), greater<char>());
        if (s == n) {
            cout << "anagram cubic" << endl;
            return 0;
        }
    }

    cout << "not cubic" << endl;
    return 0;
}