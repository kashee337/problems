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

vector<ll> makeTable(const string& s) {
    ll n = s.size();
    vector<ll> ret(n + 1);
    ret[0] = -1;
    ll j = -1;
    for (ll i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) j = ret[j];
        ret[i + 1] = ++j;
    }
    return ret;
}

vector<ll> kmp(const string& str, const string& word) {
    vector<ll> table = makeTable(word), ret;
    ll m = 0, i = 0, n = str.size();
    while (m + i < n) {
        if (word[i] == str[m + i]) {
            if (++i == (ll)(word.size())) {
                ret.push_back(m);
                m = m + i - table[i];
                i = table[i];
            }
        } else {
            m = m + i - table[i];
            if (i > 0) i = table[i];
        }
    }
    return ret;
}
constexpr ll MAX_N = 10000000000;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    string t;
    cin >> n >> t;
    string ref = "";
    ll m = ceil((double)(3 * n) / 3.0) + 2;

    rep(i, m) { ref += "110"; }
    ll cnt = 0;
    auto v = kmp(ref, t);
    cnt = v.size();
    if (cnt >= 1) {
        if (t == "1") {
            cnt = 2 * MAX_N;
        } else {
            ll dt = v[1] - v[0];
            ll st = v[0];
            ll d = (3 * MAX_N) - (st + n);
            cnt = 1LL + floor(d / dt);
        }
    }
    cout << cnt << endl;
    return 0;
}