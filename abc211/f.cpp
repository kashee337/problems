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
vector<string> s;
set<vector<string>> memo;
int n, k;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
stack<pair<int, int>> st;
int cnt;
void dfs(int x, int y) {
    if (cnt == k) {
        memo.insert(s);
        ll _x = st.top().first;
        ll _y = st.top().second;
        st.pop();
        s[_y][_x] = '.';
        cnt -= 1;
        return;
    }

    rep(i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (s[ny][nx] == '.') {
            s[ny][nx] = '@';
            st.push({nx, ny});
            cnt += 1;
            dfs(nx, ny);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    s.resize(n);
    rep(i, n) { cin >> s[i]; }
    ll res = 0;
    rep(y, n) {
        rep(x, n) {
            if (s[y][x] == '.') {
                s[y][x] = '@';
                cnt = 1;
                dfs(x, y);
                rep(_y, n) {
                    rep(_x, n) {
                        if (s[_y][_x] == '@') s[_y][_x] = '.';
                    }
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}
