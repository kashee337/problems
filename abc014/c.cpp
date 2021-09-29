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
constexpr long long MAX = 1000001;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> enogu(MAX, 0);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        enogu[a]++;
        enogu[b + 1]--;
    }
    ll max_value = enogu[0];
    reps(i, MAX, 1) {
        enogu[i] += enogu[i - 1];
        if (max_value < enogu[i]) { max_value = enogu[i]; }
    }
    cout << max_value << endl;
    return 0;
}