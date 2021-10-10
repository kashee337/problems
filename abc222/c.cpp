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

int check(char c1, char c2) {
    if (c1 == c2)
        return 0;
    else if ((c1 == 'G' && c2 == 'C') || (c1 == 'C' && c2 == 'P') || c1 == 'P' && c2 == 'G')
        return 1;
    else
        return -1;
}
bool compare(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first > b.first;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<string> a(2 * n);
    rep(i, 2 * n) cin >> a[i];
    vector<pair<ll, ll>> score(2 * n);
    rep(i, 2 * n) score[i] = {0, i};

    rep(k, m) {
        rep(i, n) {
            int idx_1 = score[2 * i].second;
            int idx_2 = score[2 * i + 1].second;
            int result = check(a[idx_1][k], a[idx_2][k]);
            if (result == 1) {
                score[2 * i].first++;
            } else if (result == -1) {
                score[2 * i + 1].first++;
            }
        }
        sort(score.begin(), score.end(), compare);
    }
    rep(i, n) {
        cout << score[2 * i].second + 1 << endl;
        cout << score[2 * i + 1].second + 1 << endl;
    }
    return 0;
}