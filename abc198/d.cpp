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
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    set<char> s;
    for (auto c : s1) s.insert(c);
    for (auto c : s2) s.insert(c);
    for (auto c : s3) s.insert(c);
    if (s.size() > 10) {
        cout << "UNSOLVABLE" << endl;
    } else {
        vector<char> num;
        rep(i, 10) num.pb(i + '0');
        vector<char> _s;
        for (auto c : s) _s.pb(c);
        do {
            map<char, char> d;
            rep(i, _s.size()) d[_s[i]] = num[i];
            string ns1 = "", ns2 = "", ns3 = "";
            for (auto c : s1) ns1 += d[c];
            for (auto c : s2) ns2 += d[c];
            for (auto c : s3) ns3 += d[c];
            if (ns1[0] == '0' || ns2[0] == '0' || ns3[0] == '0') continue;
            ll n1 = stol(ns1), n2 = stol(ns2), n3 = stol(ns3);
            if (n1 + n2 == n3) {
                cout << n1 << endl;
                cout << n2 << endl;
                cout << n3 << endl;
                return 0;
            }
        } while (next_permutation(num.begin(), num.end()));
        cout << "UNSOLVABLE" << endl;
    }
    return 0;
}