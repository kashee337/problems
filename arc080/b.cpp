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
    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> sqs(h, vector<int>(w, 0));
    int c = 1;
    int num = 0;
    rep(y, h) {
        rep(x, w) {
            if (y % 2 == 0) {
                sqs[y][x] = c;
                num++;
            } else {
                sqs[y][w - 1 - x] = c;
                num++;
            }
            if (num == a[c - 1]) {
                num = 0;
                c++;
            }
        }
    }

    rep(y, h) {
        rep(x, w) { cout << sqs[y][x] << " "; }
        cout << endl;
    }

    return 0;
}