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
    map<int, int> a, b;
    vector<pair<int, int>> ab(n);
    rep(i, n) {
        cin >> ab[i].first >> ab[i].second;
        a[ab[i].first]++;
        b[ab[i].second]++;
    }
    set<int> colors;
    for (auto v : ab) {
        int _a = v.first, _b = v.second;
        if (colors.count(_a) && !colors.count(_b)) {
            colors.insert(_b);
        } else if (colors.count(_b)) {
            colors.insert(_a);
        } else {
            if (b[_a] == 0 && a[_b] != 0) {
                colors.insert(_a);
            } else if (b[_a] != 0 && a[_b] == 0) {
                colors.insert(_b);
            } else {
                if (a[_a] > b[_b]) {
                    colors.insert(_b);
                } else {
                    colors.insert(_a);
                }
            }
        }
    }
    cout << colors.size() << endl;
    return 0;
}
