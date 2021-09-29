#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>

#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n, s) for (int i = (s); i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define rreps(i, n, s) for (int i = s; i >= n; i--)
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    int ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;
    ch--, cw--, dh--, dw--;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<int>> Area(h, vector<int>(w, 0));
    int num = 1;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    queue<pair<int, int>> q;
    rep(y, h)
    {
        rep(x, w)
        {
            if (s[y][x] == '.' && Area[y][x] == 0)
            {
                Area[y][x] = num;
                q.push({y, x});
                while (!q.empty())
                {
                    auto p = q.front();
                    q.pop();
                    int _x = p.second;
                    int _y = p.first;
                    rep(i, 4)
                    {
                        int nx = _x + dx[i];
                        int ny = _y + dy[i];
                        if (nx < 0 || ny < 0 || nx >= w || ny >= h || s[ny][nx] == '#')
                            continue;
                        if (Area[ny][nx] > 0)
                            continue;
                        q.push({ny, nx});
                        Area[ny][nx] = num;
                    }
                }
                num++;
            }
        }
    }
    int dx2[5] = {-2, -1, 0, 1, 2};
    int dy2[5] = {-2, -1, 0, 1, 2};
    vector<set<int>> warp(num - 1);
    rep(y, h)
    {
        rep(x, w)
        {
            if (s[y][x] == '.')
            {
                rep(i, 5)
                {
                    rep(j, 5)
                    {
                        int nx = x + dx2[i];
                        int ny = y + dy2[j];
                        if (nx < 0 || ny < 0 || nx >= w || ny >= h || s[ny][nx] == '#')
                            continue;
                        if (Area[y][x] != Area[ny][nx])
                        {
                            warp[Area[y][x] - 1].insert(Area[ny][nx] - 1);
                        }
                    }
                }
            }
        }
    }

    vector<int> used(num - 1, -1);
    int start = Area[ch][cw] - 1;
    int goal = Area[dh][dw] - 1;
    int res = -1;
    used[start] = 1;
    q.push({0, start});
    while (!q.empty())
    {
        auto d = q.front();
        q.pop();
        int num = d.first;
        int area = d.second;
        if (area == goal)
        {
            res = num;
            break;
        }
        for (auto a : warp[area])
        {
            if (used[a] < 0)
            {
                q.push({num + 1, a});
                used[a] = 1;
            }
        }
    }
    cout << res << endl;
    return 0;
}