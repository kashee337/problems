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
    vector<pair<ll, ll>> ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;
    vector<pair<ll, ll>> t(n);
    rep(i, n) { t[i] = {ab[i].first + ab[i].second, i}; }
    sort(t.begin(), t.end(), greater<pair<ll, ll>>());
    ll ts = 0, as = 0;
    rep(i, n) {
        if (i % 2 == 0)
            ts += ab[t[i].second].first;
        else
            as += ab[t[i].second].second;
    }
    cout << ts - as << endl;
    return 0;
}