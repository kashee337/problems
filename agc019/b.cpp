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
    string a;
    cin >> a;
    ll n = a.size();
    ll res = 1;
    rep(i, n) { res += (n - i - 1); }
    ll overwrap = 0;
    map<char, ll> memo;
    rep(i, n) {
        if (memo[a[i]] > 0) { overwrap += memo[a[i]]; }
        memo[a[i]]++;
    }
    res -= overwrap;
    cout << res << endl;
    return 0;
}