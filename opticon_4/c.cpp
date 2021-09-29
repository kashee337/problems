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
    map<char, int> dic;
    for (char c : s) { dic[c]++; }
    ll cnt = 0;
    char center;
    for (auto v : dic) {
        if (v.second != 2 && v.first != 'x') {
            cnt++;
            center = v.first;
        }
    }
    if (cnt <= 1) {
        ll c;
        rep(i, n) {
            if (s[i] == center) { c = i; }
        }
        int offset_l = 0, offset_r = 0;
        ll res = 0;
        rep(i, c) {
            int idx_l = c - i - 1;
            int idx_r = c + i + 1;
            char cl = s[idx_l];
            char cr = s[idx_r];
            if (cl == cr) continue;
            if (cr == 'x') {
                s.insert(idx_l + 1, "x");
                res++;
            } else if (cl == 'x') {
                s.insert(idx_r, "x");
                res++;
            };
        }
        if ((s[0] == 'x' || s[s.size() - 1] == 'x') && s.size() % 2 == 0) {
            if (s[0] == 'x') {
                rep(i, c) {
                    if (s[i] == 'x')
                        res++;
                    else
                        break;
                }
            }
            if (s[s.size() - 1] == 'x') {
                rrep(i, c) {
                    if (s[i] == 'x')
                        res++;
                    else
                        break;
                }
            }
        }
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}