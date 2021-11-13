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
    ll n;
    cin >> n;
    vector<string> w(n);
    map<string, int> a, b;
    string res = "DRAW";
    rep(i, n) { cin >> w[i]; }
    char last = w[0][0];
    rep(i, n) {
        char first = w[i][0];
        if (i % 2 == 0) {
            if (a.count(w[i]) || last != first) {
                res = "LOSE";
                break;
            }
            a[w[i]]++;
        } else {
            if (b.count(w[i]) || last != first) {
                res = "WIN";
                break;
            }
            b[w[i]]++;
        }
        last = w[i][w[i].size() - 1];
    }
    cout << res << endl;
    return 0;
}