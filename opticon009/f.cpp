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
    ll record[6] = {0, 0, 0, 0, 0, 0};
    rep(i, n) {
        long double u, d;
        cin >> u >> d;
        if (u >= 35) { record[0]++; }
        if (u < 35 && u >= 30) { record[1]++; }
        if (u < 30 && u >= 25) { record[2]++; }
        if (d >= 25) { record[3]++; }
        if (d < 0 && u >= 0) { record[4]++; }
        if (d < 0 && u < 0) { record[5]++; }
    }
    rep(i, 6) {
        if (i == 5) {
            cout << record[i] << endl;
        } else {
            cout << record[i] << " ";
        }
    }
    return 0;
}