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
class rect {
  public:
    ll a;
    ll b;
    ll c;
    ll d;
    vector<vector<int>> valid(10001, vector<bool>(10001, 1));
    long double score(ll r) {
        ll s = (b - a) * (d - c);
        long double s_min = r > s ? s : r;
        long double s_max = r > s ? r : s;
        return 1 - 1 - (s_min / s_max);
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<pair<ll, ll>, ll>> xyr(n);
    vector<rect> rects(n);
    rep(i, n) { cin >> xyr[i].first.first >> xyr[i].first.second >> xyr[i].second; }
    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            int ox = xyr[j].first.first;
            int oy = xyr[j].first.second;
            rects[i].invalid[oy][ox] = 1;
        }
        cout << "test" << endl;
        rep(i, n) { cout << rects[i].a << " " << rects[i].c << " " << rects[i].b << " " << rects[i].d << endl; }
        return 0;
    }