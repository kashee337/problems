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
    string s;
    cin >> s;
    ll n = s.size();
    ll res = 1;
    map<char, ll> d;
    vector<char> v{'c', 'h', 'o', 'k', 'u', 'd', 'a', 'i'};
    int m = v.size();
    rrep(i, n) {
        int idx = find(v.begin(), v.end(), s[i]) - v.begin();
        if (idx == m) continue;
        if (idx == m - 1)
            d[v[idx]]++;
        else
            d[v[idx]] = (d[v[idx]] + d[v[idx + 1]]) % MOD;
    }
    cout << d['c'] << endl;
    return 0;
}