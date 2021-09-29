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
    vector<pair<ll, ll>> ab(n), cd(n);

    rep(i, n) cin >> ab[i].first >> ab[i].second;
    rep(i, n) cin >> cd[i].first >> cd[i].second;
    sort(cd.begin(), cd.end());

    string res = "Yes";

    if (n > 1) {
        sort(ab.begin(), ab.end());
        map<pair<ll, ll>, ll> memo;
        rep(i, n) {
            ll dx = ab[i].first - cd[i].first;
            ll dy = ab[i].second - cd[i].second;
            memo[{dx, dy}]++;
        }
        if (memo.size() > 1) res = "No";
        memo.clear();
        rep(rot, 3) {
            //全ての平行移動をシミュレートする
            rep(j, n) {
                ll da = ab[j].first;
                ll db = ab[j].second;
                ll dda[3] = {-da, -da, 0};
                ll ddb[3] = {0, -db, -db};
                rep(k, 3) {
                    if (res == "Yes") {
                        cout << res << endl;
                        return 0;
                    }
                    res = "Yes";
                    rep(i, n) {
                        ll a = ab[i].first + dda[k];
                        ll b = ab[i].second + ddb[k];
                        ab[i].first = -b;
                        ab[i].second = a;
                    }
                    sort(ab.begin(), ab.end());
                    rep(i, n) {
                        ll dx = ab[i].first - cd[i].first;
                        ll dy = ab[i].second - cd[i].second;
                        memo[{dx, dy}]++;
                    }
                    if (memo.size() > 1) res = "No";
                    memo.clear();
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}