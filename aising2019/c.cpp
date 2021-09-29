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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    queue<pair<int, int>> q;
    vector<vector<bool>> used(h, vector<bool>(w, false));
    ll res = 0;
    rep(x, h) {
        rep(y, w) {
            if (used[x][y]) continue;
            q.push({x, y});
            used[x][y] = true;
            map<char, ll> bw_cnt;
            while (!q.empty()) {
                auto xy = q.front();
                int x = xy.first;
                int y = xy.second;
                q.pop();
                bw_cnt[s[x][y]]++;
                rep(i, 4) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    if (used[nx][ny]) continue;
                    if (s[x][y] == s[nx][ny]) continue;
                    used[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            res += bw_cnt['#'] * bw_cnt['.'];
        }
    }

    cout << res << endl;

    return 0;
}