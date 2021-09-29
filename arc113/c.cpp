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
    int n = s.size();
    map<char, int> log;
    log[s[n - 1]]++;
    log[s[n - 2]]++;
    ll res = 0;
    rrep(i, n - 2) {
        if (s[i] == s[i + 1] && s[i] != s[i + 2]) {
            res += n - (i + 2) - (log[s[i]] - 1);
            log.clear();
            log[s[i]] = n - i;
        } else {
            log[s[i]]++;
        }
    }
    cout << res << endl;
    return 0;
}