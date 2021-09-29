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
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> t(n, vector<ll>(n, 0));
    rep(i, n) { rep(j, n) cin >> t[i][j]; }
    ll res = 0;
    vector<int> city(n);
    rep(i, n) city[i] = i;
    do {
        int s = 0;
        ll tmp = 0;
        reps(i, n, 1) {
            tmp += t[s][city[i]];
            s = city[i];
        }
        tmp += t[s][0];
        if (tmp == k) res++;
    } while (next_permutation(city.begin() + 1, city.end()));
    cout << res << endl;
    return 0;
}