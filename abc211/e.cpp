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
set<vector<string>> memo;
int n, k;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
ll res;

int count(vector<string> s) {
    int cnt = 0;
    rep(i, n) {
        rep(j, n) {
            if (s[i][j] == '@') cnt++;
        }
    }
    return cnt;
}
void dfs(vector<string> s) {
    int cnt = count(s);
    if (cnt == k) {
        res++;
        return;
    } else if (cnt > k)
        return;

    rep(y, n) {
        rep(x, n) {
            if (s[y][x] != '.') continue;
            if (cnt != 0) {
                bool ok = false;
                rep(i, 4) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (s[ny][nx] == '@') ok = true;
                }
                if (!ok) continue;
            }
            s[y][x] = '@';
            dfs(s);
            s[y][x] = '#';
            dfs(s);
            return;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    vector<string> s(n);
    rep(i, n) { cin >> s[i]; }
    dfs(s);
    cout << res << endl;
    return 0;
}
