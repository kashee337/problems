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
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(j, m) cin >> b[j];
    rep(i, n - (m - 1)) {
        rep(j, n - (m - 1)) {
            bool isMatched = true;
            rep(y, m) {
                rep(x, m) {
                    if (a[i + y][j + x] != b[y][x]) {
                        isMatched = false;
                        break;
                    }
                }
            }
            if (isMatched) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}