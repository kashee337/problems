#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
    ll n, m;
    cin >> n >> m;
    string name, kit;
    cin >> name >> kit;
    map<char, int> memo1, memo2;
    for (char c : name) {
        memo1[c]++;
        memo2[c] = 0;
    }
    for (char c : kit) memo2[c]++;
    int res = 1;
    for (auto v : memo1) {
        char c = v.first;
        int n1 = v.second;
        int n2 = memo2[c];
        if (n2 == 0) {
            res = -1;
            break;
        }
        int num = n1 / n2;
        if (n1 % n2 != 0) num++;
        res = max(res, num);
    }
    cout << res << endl;
    return 0;
}
