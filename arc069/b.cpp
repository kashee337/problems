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

char get(char m, char c, char c_past) {
    map<char, char> d;
    d['S'] = 'W';
    d['W'] = 'S';
    if (c == 'S') {
        if (m == 'o') {
            return c_past;
        } else {
            return d[c_past];
        }
    } else {
        if (m == 'o') {
            return d[c_past];
        } else {
            return c_past;
        }
    }
}
string solve(string s, char c1, char c2, char cn) {
    string t = "";
    int n = s.size();
    t += c1;
    t += c2;
    if (s[0] == 'o') {
        if (c1 == 'S') {
            if (c2 != cn) return "";
        } else {
            if (c2 == cn) return "";
        }
    } else {
        if (c1 == 'S') {
            if (c2 == cn) return "";
        } else {
            if (c2 != cn) return "";
        }
    }
    reps(i, n - 1, 1) { t += get(s[i], t[i], t[i - 1]); }
    t = t;
    if (t[n - 1] == cn) {
        char c = get(s[n - 1], t[n - 1], t[n - 2]);
        if (c == c1) {
            return t;
        } else {
            return "";
        }
    } else {
        return "";
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    string s;
    cin >> s;

    char cs[2] = {'S', 'W'};
    rep(i, 2) {
        rep(j, 2) {
            rep(k, 2) {
                string t = solve(s, cs[i], cs[j], cs[k]);
                if (t.size() > 0) {
                    cout << t << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}