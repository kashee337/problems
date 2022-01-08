#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
    ll n, a, b;
    cin >> n >> a >> b;
    ll p, q, r, s;
    cin >> p >> q >> r >> s;
    ll l1 = max(1LL - a, 1LL - b), r1 = min(n - a, n - b);
    ll l2 = max(1LL - a, b - n), r2 = min(n - a, b - 1LL);
    vector<string> res;
    for (ll i = p; i <= q; i++) {
        string tmp = "";
        for (ll j = r; j <= s; j++) {
            ll di=(i-a),dj=(j-b);
            if(abs(di)==abs(dj)){
                if((l1<=di&&di<=r1)&&(l1<=dj&&dj<=r1)){
                    tmp += "#";
                }else if((l2<=di&&di<=r2)&&(l2<=-dj&&-dj<=r2)){
                    tmp += "#";
                }
                else{
                tmp += ".";
                }
            }
            else{
                tmp += ".";
            }
        }
        res.pb(tmp);
    }
    for (string tmp : res) cout << tmp << endl;
    return 0;
}