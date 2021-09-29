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
    ll k;
    string s, t;
    cin >> k >> s >> t;
    map<ll, ll> c;
    reps(i, 10, 1) { c[i] = k; }
    map<ll, ll> sc, tc;
    rep(i, 4) {
        int sn = s[i] - '0';
        int tn = t[i] - '0';

        sc[sn]++;
        tc[tn]++;
        c[sn]--;
        c[tn]--;
    }
    vector<ll> comb;
    for (auto v : c) {
        if (v.second >= 1) { comb.pb(v.first); }
    }
    set<pair<ll, ll>> win_patterns;
    ll len = comb.size();
    rep(i, len) {
        rep(j, len) {
            if (i == j && c[comb[i]] == 1) continue;
            ll s_card = comb[i];
            ll t_card = comb[j];
            sc[s_card]++;
            tc[t_card]++;
            ll sv = 0, tv = 0;
            reps(i, 10, 1) {
                sv += i * pow(10, sc[i]);
                tv += i * pow(10, tc[i]);
            }
            if (sv > tv) { win_patterns.insert({s_card, t_card}); }
            sc[s_card]--;
            tc[t_card]--;
        }
    }
    long double p = 0;
    ll all_card_num = 9 * k - 4 * 2;
    long double all_patterns = all_card_num * (all_card_num - 1);
    ll win_nums = 0;
    for (auto wp : win_patterns) {
        ll a = c[wp.first];
        ll b = c[wp.second];
        if (wp.first == wp.second) {
            win_nums += a * (a - 1);
        } else {
            win_nums += a * b;
        }
    }
    p = (long double)(win_nums) / all_patterns;
    cout << fixed << setprecision(10) << p << endl;
    return 0;
}