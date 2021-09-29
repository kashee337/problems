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
    vector<string> s(n);
    map<string, int> dict;
    string res = "satisfiable";
    rep(i, n) {
        cin >> s[i];
        dict[s[i]]++;
        string _s;
        if (s[i][0] == '!') {
            _s = s[i].substr(1, s[i].size() - 1);
        } else {
            _s = "!" + s[i];
        }
        if (dict[_s] >= 1) {
            if (s[i][0] == '!')
                res = _s;
            else
                res = s[i];
        }
        if (res != "satisfiable") break;
    }

    cout << res << endl;
    return 0;
}