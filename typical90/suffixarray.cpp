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

class SuffixArray {
    string s;
    int n;
    vector<pair<string, int>> sa;
    // string centinel = "$";

  public:
    SuffixArray(string _s) : s(_s) {
        n = s.size();
        // s += centinel;
        for (int i = 0; i < n; i++) { sa.pb({s.substr(i, n - i), i}); }
        sort(sa.begin(), sa.end());
    }

    vector<int> search(string t) {
        int l = 0, r = n;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            string _s = sa[m].first;
            if (_s < t) {
                l = m;
            } else {
                r = m;
            }
        }
        int L = r;
        l = 0, r = n;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            string _s = sa[m].first;
            if (_s <= t) {
                l = m;
            } else {
                r = m;
            }
        }
        int R = r;
        vector<int> res;
        res.pb(sa[l].second);
        return res;
    }
    // bool query(string t,int idx){

    // }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s = "banana";
    SuffixArray sa(s);
    auto res = sa.search("ana");
    // cout <<  << endl;
    return 0;
}