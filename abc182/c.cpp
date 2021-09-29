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
    string n;
    cin >> n;
    int len = n.size();
    int min_cnt = 100;
    reps(d, 1LL << len, 1) {
        string num_str = "";
        int cnt = 0;
        rep(i, len) {
            if (d & (1 << i)) {
                num_str += n[i];
            } else {
                cnt++;
            }
        }
        if (min_cnt > cnt) {
            ll num = stol(num_str);
            if (num % 3 == 0) { min_cnt = cnt; }
        }
    }
    if (min_cnt == 100) min_cnt = -1;
    cout << min_cnt << endl;
    return 0;
}