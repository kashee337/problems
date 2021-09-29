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
    vector<ll> p(n);
    map<int, int> m;
    rep(i, n) {
        cin >> p[i];
        p[i]--;
        m[p[i]] = i;
    }
    vector<int> res;
    vector<bool> done(n, false);
    rep(k, n) {
        if (m[k] != k) {
            while (m[k] != k) {
                ll right = m[k];
                ll left = right - 1;
                if (done[left]) break;
                done[left] = true;
                swap(p[right], p[left]);
                m[p[right]] = right;
                m[p[left]] = left;
                res.pb(left);
            }
        }
    }

    bool ok = true;
    rep(i, n - 1) {
        if (p[i + 1] < p[i]) {
            ok = false;
            break;
        }
    }
    if (res.size() != n - 1) { ok = false; }
    if (ok) {
        for (auto idx : res) cout << idx + 1 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}